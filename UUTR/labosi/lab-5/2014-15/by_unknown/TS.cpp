#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

std::vector<std::string> split_string(const std::string &, char = ',');

struct TS_definition
{
	std::string states;
	std::string alphabet;
	std::string track_alphabet;
	std::vector<std::string> transitions;
	std::string starting_state;
	std::string empty_sign;
	std::string accepted_states;
};

class State
{
public:
	State(const std::vector<std::string> &, bool);
	std::tuple<std::string, std::string, std::string> transition(const std::string &);
	bool is_accepted() const { return m_accepted; }
private:
	std::map<std::string, std::tuple<std::string, std::string, std::string>> m_transitions;
	bool m_accepted;
};

class TS
{
public:
	TS(const TS_definition &);
	std::pair<std::string, bool> go(std::string &, int &);
private:
	std::map<std::string, State> m_states;
	std::set<std::string> m_alphabet;
	std::set<std::string> m_track_alphabet;
	std::string m_starting_state;
	std::string m_empty_sign;
};

int main()
{
	TS_definition definition;
	std::string input;
	std::string track;
	std::getline(std::cin, definition.states);
	std::getline(std::cin, definition.alphabet);
	std::getline(std::cin, definition.track_alphabet);
	std::getline(std::cin, definition.empty_sign);
	std::getline(std::cin, track);
	std::getline(std::cin, definition.accepted_states);
	std::getline(std::cin, definition.starting_state);
	std::getline(std::cin, input);
	int position = std::stoi(input);
	while(std::cin >> input)
	{
		definition.transitions.emplace_back(input);
	}
	TS ts(definition);
	std::pair<std::string, bool> out = ts.go(track, position);
	std::cout << out.first + "|" << position << "|" + track + "|" + (out.second ? "1" : "0") << std::endl;
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

State::State(const std::vector<std::string> &transitions, bool accepted)
	: m_accepted(accepted)
{
	for(const auto &transition : transitions)
	{
		std::string symbol{ split_string(transition.substr(0, transition.find('-')))[1] };
		std::vector<std::string> right{ split_string(transition.substr(transition.find('>') + 1)) };
		m_transitions.emplace(symbol, std::make_tuple(right[0], right[1], right[2]));
	}
}

std::tuple<std::string, std::string, std::string> State::transition(const std::string &symbol)
{
	if(m_transitions.count(symbol) == 0)
	{
		return std::make_tuple("FAIL", "", "");
	}
	return m_transitions.at(symbol);
}

TS::TS(const TS_definition &definition)
	: m_starting_state(definition.starting_state),
	m_empty_sign(definition.empty_sign)
{
	std::vector<std::string> alphabet{ split_string(definition.alphabet) };
	m_alphabet = { alphabet.begin(), alphabet.end() };

	std::vector<std::string> track_alphabet{ split_string(definition.track_alphabet) };
	m_track_alphabet = { track_alphabet.begin(), track_alphabet.end() };

	std::vector<std::string> accepted_states{ split_string(definition.accepted_states) };
	for(const auto &state_name : split_string(definition.states))
	{
		bool is_accepted{ std::find(accepted_states.begin(), accepted_states.end(), state_name) != accepted_states.end() };
		std::vector<std::string> matching_transitions;
		std::regex pattern{ state_name + ",(.*)" };
		for(const auto &transition : definition.transitions)
		{
			if(std::regex_match(transition, pattern) == true)
			{
				matching_transitions.emplace_back(transition);
			}
		}
		m_states.insert({ state_name, { matching_transitions, is_accepted } });
	}
}

std::pair<std::string, bool> TS::go(std::string &track, int &position)
{
	std::string current_state{ m_starting_state };
	int new_position{ position };
	while(new_position >= 0 && new_position < 70)
	{
		position = new_position;
		std::tuple<std::string, std::string, std::string> transition = m_states.at(current_state).transition(std::string(1, track[position]));
		if(transition == std::make_tuple("FAIL", "", "") || (std::get<2>(transition) == "R" && position == 69) || (std::get<2>(transition) == "L" && position == 0))
		{
			break;
		}
		current_state = std::get<0>(transition);
		new_position = position + (std::get<2>(transition) == "R" ? 1 : -1);
		track[position] = std::get<1>(transition)[0];
	}
	return std::make_pair(current_state, m_states.at(current_state).is_accepted());
}