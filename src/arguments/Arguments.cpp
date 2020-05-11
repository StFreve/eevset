#include "arguments/Arguments.h"

Arguments::Arguments()
{
}

Arguments& Arguments::add_argument(ArgumentInfoBase& argument)
{
	return *this;
}

Arguments& Arguments::set_env_variable_argument(std::string& environment_variable_name, std::string& environment_variable_value)
{
	return *this;
}

void Arguments::set_help_main_message(const std::string& help)
{
}

void Arguments::set_usage_format_message(const std::string& help)
{
}

void Arguments::parse_arguments(int argc, const char* argv[])
{
}

void Arguments::print_arguments_usage() const
{
}

void Arguments::print_help() const
{
}
