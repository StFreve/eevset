#pragma once
#include <string>
#include <map>

class SettignsParser
{
public:
	SettignsParser(const std::string& settings_file_path);

	template<class ValueType = std::string>
	ValueType get_setting_value(const std::string& setting_name, const ValueType& default_value);

	template<class ValueType = std::string>
	void set_setting_value(const std::string& setting_name, const ValueType& value);
	
	void reload();
	void save();

private:

	std::string settings_file_path;
	std::map<std::string, std::string> settings;
};