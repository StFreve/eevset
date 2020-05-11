#pragma once
#include <set>
#include <string>
#include <utils/lexical_cast.h>

class ArgumentInfoBase
{
public:
    ArgumentInfoBase(const std::set<std::string> &full_arg_name, const std::set<char> &short_arg_name, const std::string& help_message);
    virtual ~ArgumentInfoBase();

    std::set<std::string> get_full_argument_names();
    std::set<std::string> get_short_argument_names();
    std::string get_help_message();
   
    virtual const char** parse_value(const char** argv) = 0;

private:
    std::set<std::string> full_argument_names_;
    std::set<char> short_argument_names_;
    std::string help_message_;
};

template<class ArgumentType>
class SimpleArgumentInfo : public ArgumentInfoBase
{
public:
	SimpleArgumentInfo(const std::set<std::string> &full_arg_name, const std::set<char> &short_arg_name, const std::string& help_message, const ArgumentType& default_value);

    virtual const char** parse_value(const char** argv) override
    {
        if(argv == NULL || argv[0] == NULL)
        {
            return &argv[0];
        }
        
        value = utils::template lexical_cast<ArgumentType>(argv[0]);
        return &argv[1];
    }

    ArgumentType get_argument_value() const
    {
        return value;
    }

protected:
    ArgumentType value;
};

class FlagArgumentInfo : public SimpleArgumentInfo<bool>
{
public:
	FlagArgumentInfo(const std::set<std::string>& full_arg_name, const std::set<char>& short_arg_name, const std::string& help_message);

	virtual const char** parse_value(const char** argv) override
	{
		value = true;
		return argv;
	}
};


typedef SimpleArgumentInfo<int> IntegerArgument;
typedef SimpleArgumentInfo<double> RealNumberArgument;
typedef SimpleArgumentInfo<bool> BooleanArgument;
typedef SimpleArgumentInfo<std::string> StringArgument;