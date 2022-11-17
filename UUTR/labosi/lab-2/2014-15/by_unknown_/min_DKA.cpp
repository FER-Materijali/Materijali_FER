#include <algorithm>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> split_string(const std::string &, char = ',');
std::string set_to_string(const std::set<std::string> &);

class State
{
	friend std::ostream &operator<<(std::ostream &, const State &);
public:
	State(const std::string &, std::vector<std::string> &, bool);
	std::string transition(const std::string &) const;
	std::string state_name() const { return m_state_name; }
	bool is_accepted() const { return m_accepted; }
	void remove_from_transitions(const std::pair<std::string, std::string> &);
private:
	std::map<std::string, std::string> m_transition;
	std::string m_state_name;
	bool m_accepted;
};

std::ostream &operator<<(std::ostream &, const State &);

struct Element
{
	Element(const std::string &, const std::string &, bool);
	std::string first_state;
	std::string second_state;
	bool marked;
};

class DKA
{
	friend std::ostream &operator<<(std::ostream &, const DKA &);
public:
	DKA(const std::string &, const std::string &, const std::vector<std::string> &, const std::string &, const std::string &);
	void minimize() { remove_unreachable_states(); remove_nondistinguishable_states(find_nondistinguishable_states()); }
private:
	std::map<std::string, State> m_states;
	std::set<std::string> m_alphabet;
	std::string m_start_state;

	void remove_unreachable_states();
	std::vector<std::pair<std::string, std::string>> find_nondistinguishable_states();
	void remove_nondistinguishable_states(const std::vector<std::pair<std::string, std::string>> &);
};

std::ostream &operator<<(std::ostream &, const DKA &);

int main()
{
	std::string states;
	std::getline(std::cin, states);
	std::string alphabet;
	std::getline(std::cin, alphabet);
	std::string accepted_states;
	std::getline(std::cin, accepted_states);
	std::string start_state;
	std::getline(std::cin, start_state);
	std::vector<std::string> transitions;
	std::string transition;
	while(std::getline(std::cin, transition))
	{
		transitions.emplace_back(transition);
	}

	DKA automat(states, alphabet, transitions, start_state, accepted_states);
	automat.minimize();
	std::cout << automat;
	return 0;
}

std::vector<std::string> split_string(const std::string &input, char delimiter)
{
	std::istringstream input_stream{ input };
	std::string sub_string;
	std::vector<std::string> tokens;
	while(std::getline(input_stream, sub_string, delimiter))
	{
		tokens.emplace_back(sub_string);
	}
	return tokens;
}

std::string set_to_string(const std::set<std::string> &set)
{
	if(set.empty() == true)
	{
		return "";
	}
	std::string output;
	std::for_each(set.begin(), set.end(), [&output](std::string state) { output += state + ","; });
	output.pop_back();
	return output;
}

State::State(const std::string &state_name, std::vector<std::string> &transitions, bool accepted)
	: m_state_name(state_name), m_accepted(accepted)
{
	for(const auto &transition : transitions)
	{
		std::string symbol{ transition.substr(transition.find(',') + 1, transition.find('-') - transition.find(',') - 1) };
		std::string next_state{ transition.substr(transition.find('>') + 1, transition.size() - transition.find('>') - 1) };
		m_transition[symbol] = next_state;
	}
}

std::string State::transition(const std::string &symbol) const
{
	return m_transition.at(symbol);
}

void State::remove_from_transitions(const std::pair<std::string, std::string> &n_states)
{
	for(auto &transition : m_transition)
	{
		if(transition.second == n_states.second)
		{
			transition.second = n_states.first;
		}
	}
}

std::ostream &operator<<(std::ostream &out, const State &item)
{
	for(const auto &transition : item.m_transition)
	{
		out << item.state_name() << "," << transition.first << "->" << transition.second << std::endl;
	}
	return out;
}

DKA::DKA(const std::string &s, const std::string &a, const std::vector<std::string> &t, const std::string &s_s, const std::string &a_s)
	: m_start_state(s_s)
{
	std::vector<std::string> alphabet{ split_string(a) };
	m_alphabet = { alphabet.begin(), alphabet.end() };

	std::vector<std::string> accepted_states{ split_string(a_s) };
	for(auto &state_name : split_string(s))
	{
		bool is_accepted{ std::find(accepted_states.begin(), accepted_states.end(), state_name) != accepted_states.end() };
		std::vector<std::string> matching_transitions;
		std::regex pattern{ state_name + ",(.*)" };
		for(const auto &transition : t)
		{
			if(std::regex_match(transition, pattern) == true)
			{
				matching_transitions.emplace_back(transition);
			}
		}
		m_states.insert({ state_name, { state_name, matching_transitions, is_accepted } });
	}
 }

void DKA::remove_unreachable_states()
{
	std::set<std::string> reachable_states;
	std::set<std::string> new_reachable_states{ m_start_state };
	do
	{	
		reachable_states = new_reachable_states;
		for(const auto &state_name : new_reachable_states)
		{
			for(const auto &symbol : m_alphabet)
			{
				new_reachable_states.insert(m_states.at(state_name).transition(symbol));
			}
		}
	} while(reachable_states != new_reachable_states);

	std::vector<std::map<std::string, State>::iterator> unreachable_states;
	for(std::map<std::string, State>::iterator it{ m_states.begin() }; it != m_states.end(); ++it)
	{
		if(reachable_states.count(it->first) == 0)
		{
			unreachable_states.emplace_back(it);
		}
	}
	for(auto i : unreachable_states)
	{
		m_states.erase(i);
	}
}

std::vector<std::pair<std::string, std::string>> DKA::find_nondistinguishable_states()
{
	std::vector<std::string> name_lookup;
	for(const auto &state : m_states)
	{
		name_lookup.emplace_back(state.first);
	}
	std::vector<Element> state_pairs;
	for(size_t x{ 0 }; x != name_lookup.size() - 1; ++x)
	{
		for(size_t y{ x + 1 }; y != name_lookup.size(); ++y)
		{
			bool distinct{ m_states.at(name_lookup[x]).is_accepted() != m_states.at(name_lookup[y]).is_accepted() };
			state_pairs.emplace_back(name_lookup[x], name_lookup[y], distinct);
		}
	}

	bool pair_marked;
	do
	{
		pair_marked = false;
		for(auto &state_pair : state_pairs)
		{
			if(state_pair.marked == false)
			{
				for(const auto &symbol : m_alphabet)
				{
					Element next{ m_states.at(state_pair.first_state).transition(symbol), m_states.at(state_pair.second_state).transition(symbol), false };
					if(next.first_state != next.second_state)
					{
						if(find(state_pairs.begin(), state_pairs.end(), next)->marked == true)
						{
							state_pair.marked = true;
							pair_marked = true;
						}
					}
				}
			}
		}
	} while(pair_marked == true);

	std::vector<std::pair<std::string, std::string>> nondistinguishable_states;
	for(const auto &state_pair : state_pairs)
	{
		if(state_pair.marked == false)
		{
			nondistinguishable_states.emplace_back(state_pair.first_state, state_pair.second_state);
		}
	}
	return nondistinguishable_states;
}

void DKA::remove_nondistinguishable_states(const std::vector<std::pair<std::string, std::string>> &n_states)
{
	std::vector<std::string> nondistinguishable_states;
	for(auto it = n_states.rbegin(); it != n_states.rend(); ++it)
	{
		for(auto &state : m_states)
		{
			state.second.remove_from_transitions(*it);
		}
		nondistinguishable_states.emplace_back(it->second);
		if(it->second == m_start_state)
		{
			m_start_state = it->first;
		}
	}
	for(const auto &state : nondistinguishable_states)
	{
		m_states.erase(state);
	}
}

std::ostream &operator<<(std::ostream &out, const DKA &item)
{
	std::set<std::string> states;
	std::set<std::string> accepted_states;
	for(const auto &state : item.m_states)
	{
		states.emplace(state.first);
		if(state.second.is_accepted() == true)
		{
			accepted_states.emplace(state.first);
		}
	}
	out << set_to_string(states) << std::endl;
	out << set_to_string(item.m_alphabet) << std::endl;
	out << set_to_string(accepted_states) << std::endl;
	out << item.m_start_state << std::endl;
	for(const auto &state : item.m_states)
	{
		out << state.second;
	}
	return out;
}

Element::Element(const std::string &first, const std::string &second, bool dist)
	: first_state(first < second ? first : second), second_state(first < second ? second : first), marked(dist)
{}

bool operator==(const Element &left, const Element &right)
{
	return (left.first_state == right.first_state) && (left.second_state == right.second_state);
}