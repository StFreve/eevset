#pragma once
#include <sstream>
#include <exception>
#include <type_traits>

namespace utils
{

template<class ToType, class FromType>
ToType lexical_cast_internal(const FromType& value)
{
	try {
		ToType out_value;
		std::stringstream stream;
		stream << value;
		if (stream.fail()) {
			throw std::runtime_error("Source type value could not be interpreted as target");
		}
		stream >> out_value;
		if (stream.fail()) {
			throw std::runtime_error("Source type value could not be interpreted as target");
		}
		return out_value;
	}
	catch (...) {
		throw std::runtime_error("Source type value could not be interpreted as target");
	}
}

template<>
inline std::string lexical_cast_internal(const bool& value)
{
	return value ? "true" : "false";
}

template<>
inline bool lexical_cast_internal(const std::string& str)
{
	//TODO: Add more variants and make case insensetive
	if (str == "true") {
		return true;
	}
	else if (str == "false") {
		return false;
	}
	throw std::runtime_error("Source type value could not be interpreted as target");
}

template<>
inline bool lexical_cast_internal(const char* const& str)
{
	return lexical_cast_internal<bool, std::string>(str);
}

template<class T>
struct array_to_pointer_decay
{
	typedef T type;
};

template<class T, std::size_t N>
struct array_to_pointer_decay<T[N]>
{
	typedef const T* type;
};

template<class ToType, class FromType>
ToType lexical_cast(const FromType& value)
{
	typedef typename array_to_pointer_decay<FromType>::type FromTypeFixed;

	return lexical_cast_internal<ToType, FromTypeFixed>(value);
}

} // namespace utils
