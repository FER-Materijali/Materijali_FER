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
public:
	State(const std::vector<std::string> &, bool);
	std::set<std::string> transition(const std::string &) const;
	bool is_accepted() const { return m_accepted; }
private:
	std::map<std::string, std::set<std::string>> m_transition;
	bool m_accepted;
};

class eNKA
{
public:
	eNKA(const std::string &, const std::string &, const std::vector<std::string> &, const std::string &, const std::string &);
	std::ostream &operator<<(const std::string &) const;
	std::set<std::string> e_closure(const std::string &state) const;
private:
	std::map<std::string, State> m_states;
	std::set<std::string> m_alphabet;
	std::string m_start_state;
};

int main()
{
	std::string input;
	std::getline(std::cin, input);
	std::vector<std::string> input_sequences{ split_string(input, '|') };
	std::string states;
	std::getline(std::cin, states);
	std::string alphabet;
	std::getline(std::cin, alphabet);
	std::string accepted_states;
	std::getline(std::cin, accepted_states);
	std::string start_state;
	std::getline(std::cin, start_state);
	std::vector<std::string> transitions;
	while(std::getline(std::cin, input))
	{
		transitions.emplace_back(input);
	}
	eNKA automat(states, alphabet, transitions, start_state, accepted_states);
	for(const auto &input_sequence : input_sequences)
	{
		automat << input_sequence << std::endl;
	}
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
		return "#";
	}
	std::string output;
	std::for_each(set.begin(), set.end(), [&output](std::string state) { output += state + ","; });
	output.pop_back();
	return output;
}

State::State(const std::vector<std::string> &transitions, bool accepted)
	: m_accepted(accepted)
{
	for(const auto &transition : transitions)
	{
		std::string symbol{ transition.substr(transition.find(',') + 1, transition.find('-') - transition.find(',') - 1) };
		std::vector<std::string> next_states{ split_string(transition.substr(transition.find('>') + 1, transition.size() - transition.find('>') - 1)) };
		for(const auto &state : next_states)
		{
			if(state != "#")
			{
				m_transition[symbol].emplace(state);
			}
		}
	}
}

std::set<std::string> State::transition(const std::string &symbol) const
{
	return m_transition.count(symbol) == 1 ? m_transition.at(symbol) : std::set<std::string>();
}

eNKA::eNKA(const std::string &s, const std::string &a, const std::vector<std::string> &t, const std::string &s_s, const std::string &a_s)
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
		m_states.insert({ state_name, { matching_transitions, is_accepted } });
	}
}

std::ostream &eNKA::operator<<(const std::string &input_sequence) const
{
	std::set<std::string> current_e_closure{ e_closure(m_start_state) };
	std::string output;
	for(const auto &symbol : split_string(input_sequence))
	{
		output += set_to_string(current_e_closure) + "|";
		std::set<std::string> new_e_closure;
		for(const auto &state : current_e_closure)
		{
			for(const auto &new_state : m_states.at(state).transition(symbol))
			{
				new_e_closure.emplace(new_state);
			}
		}
		current_e_closure.clear();
		for(const auto &state : new_e_closure)
		{
			for(const auto &new_e_state : e_closure(state))
			{
				current_e_closure.emplace(new_e_state);
			}
		}
	}
	output += set_to_string(current_e_closure);
	return std::cout << output;
}

std::set<std::string> eNKA::e_closure(const std::string &state) const
{
	std::set<std::string> closure{ state };
	std::set<std::string> unchecked_states{ m_states.at(state).transition("$") };
	std::set<std::string> visited_states{ state };
	static std::map<std::string, std::set<std::string>> found_e_closures;
	if(found_e_closures.count(state) == 0)
	{
		while(unchecked_states.empty() == false)
		{
			std::set<std::string> new_e_transitions;
			for(const auto &found_state : unchecked_states)
			{
				closure.emplace(found_state);
				if(visited_states.count(found_state) == 0)
				{
					for(const auto &new_state : m_states.at(found_state).transition("$"))
					{
						new_e_transitions.emplace(new_state);
					}
					visited_states.emplace(found_state);
				}
			}
			unchecked_states = new_e_transitions;
		}
		found_e_closures.insert({ state, closure });
	}
	return found_e_closures.at(state);
}