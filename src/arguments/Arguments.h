#pragma once
#include <set>
#include <vector>
#include <string>
#include "arguments/ArgumentInfo.h"

// Class Aguments is used to parse argument list passed to the executable.
class Arguments
{
public:
	Arguments();

	// Specify argument
	Arguments& add_argument(ArgumentInfoBase& argument);

	// Always is the last parameter of arguments list
	Arguments& set_env_variable_argument(std::string& environment_variable_name, std::string& environment_variable_value);

	void set_help_main_message(const std::string& help);
	void set_usage_format_message(const std::string& help);

	// Parse argument list. Should be used only after all other information is specified.
	// Will print usage and throw an exception if fails to parse arguments list
	void parse_arguments(int argc, const char* argv[]);

	// Prints usage if fails to parse argument list.
	void print_arguments_usage() const;

	// Print help message
	void print_help() const;
private:
};