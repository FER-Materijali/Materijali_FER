#include <algorithm>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

std::vector<std::string> split_string(const std::string &, char = ',');

class State
{
public:
	State(const std::vector<std::string> &, bool);
	std::pair<std::string, std::string> transition(const std::string &, const std::string &);
	bool is_accepted() const { return m_accepted; }
private:
	std::map<std::pair<std::string, std::string>, std::pair<std::string, std::string>> m_transitions;
	bool m_accepted;
};

class PA
{
public:
	PA(const std::string &, const std::string &, const std::string &, const std::vector<std::string> &, const std::string &, const std::string &, const std::string &);
	void read_sequence(const std::string &, std::ostream & = std::cout);
private:
	std::map<std::string, State> m_states;
	std::set<std::string> m_alphabet;
	std::set<std::string> m_stack_alphabet;
	std::string m_start_state;
	std::string m_stack_start_symbol;
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
	std::string stack_alphabet;
	std::getline(std::cin, stack_alphabet);
	std::string accepted_states;
	std::getline(std::cin, accepted_states);
	std::string start_state;
	std::getline(std::cin, start_state);
	std::string stack_start_symbol;
	std::getline(std::cin, stack_start_symbol);
	std::vector<std::string> transitions;
	while(std::getline(std::cin, input))
	{
		transitions.emplace_back(input);
	}
	PA pa(states, alphabet, stack_alphabet, transitions, start_state, stack_start_symbol, accepted_states);
	for(const auto &sequence : input_sequences)
	{
		pa.read_sequence(sequence);
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

State::State(const std::vector<std::string> &transitions, bool accepted)
	: m_accepted(accepted)
{
	for(const auto &transition : transitions)
	{
		std::vector<std::string> left{ split_string(transition.substr(0, transition.find('-'))) };
		std::vector<std::string> right{ split_string(transition.substr(transition.find('>') + 1, transition.size() - transition.find('>') - 1)) };
		if(right[1] == "$")
		{
			right[1] = "";
		}
		std::pair<std::string, std::string> input_pair{ left[1], left[2] };
		std::pair<std::string, std::string> output_pair{ right[0], right[1] };
		m_transitions[input_pair] = output_pair;
	}
}

std::pair<std::string, std::string> State::transition(const std::string &symbol, const std::string &stack_symbol)
{
	std::pair<std::string, std::string> input_pair{ symbol, stack_symbol };
	if(m_transitions.count(input_pair) == 0)
	{
		return{ "fail", "" };
	}
	return m_transitions[input_pair];
}

PA::PA(const std::string &s, const std::string &a, const std::string &s_a, const std::vector<std::string> &t,
	const std::string &s_s, const std::string &s_s_s, const std::string &a_s)
	: m_start_state(s_s), m_stack_start_symbol(s_s_s)
{
	std::vector<std::string> alphabet{ split_string(a) };
	m_alphabet = { alphabet.begin(), alphabet.end() };

	std::vector<std::string> stack_alphabet{ split_string(s_a) };
	m_stack_alphabet = { stack_alphabet.begin(), stack_alphabet.end() };

	std::vector<std::string> accepted_states{ split_string(a_s) };
	for(const auto &state_name : split_string(s))
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

void PA::read_sequence(const std::string &input, std::ostream &out)
{
	std::pair<std::string, std::string> fail{ "fail", "" };

	std::string current_state{ m_start_state };
	std::string stack{ m_stack_start_symbol };

	out << current_state + "#" + (stack.empty() == true ? "$" : stack) + "|";
	std::vector<std::string> input_sequence{ split_string(input) };
	for(std::vector<std::string>::iterator it{ input_sequence.begin() }; it != input_sequence.end();)
	{
		std::string symbol{ *it };
		std::pair<std::string, std::string> transition{ m_states.at(current_state).transition(symbol, std::string(1, stack[0])) };
		std::pair<std::string, std::string> epsilon_transition{ m_states.at(current_state).transition("$", std::string(1, stack[0])) };
		if(transition != fail)
		{
			stack = transition.second + stack.substr(1, stack.length() - 1);
			current_state = transition.first;
			++it;
		}
		else if(epsilon_transition != fail)
		{
			stack = epsilon_transition.second + stack.substr(1, stack.length() - 1);
			current_state = epsilon_transition.first;
		}
		else
		{
			current_state = "fail";
			break;
		}
		out << current_state + "#" + (stack.empty() == true ? "$" : stack) + "|";
	}
	if(current_state != "fail")
	{
		if(m_states.at(current_state).is_accepted() == false)
		{
			while(m_states.at(current_state).transition("$", std::string(1, stack[0])) != fail)
			{
				std::pair<std::string, std::string> epsilon_transition{ m_states.at(current_state).transition("$", std::string(1, stack[0])) };
				stack = epsilon_transition.second + stack.substr(1, stack.length() - 1);
				current_state = epsilon_transition.first;
				out << current_state + "#" + (stack.empty() == true ? "$" : stack) + "|";

				if(m_states.at(current_state).is_accepted() == true)
				{
					break;
				}
			}
		}
		out << m_states.at(current_state).is_accepted() << std::endl;
	}
	else
	{
		out << "fail|0" << std::endl;
	}
}