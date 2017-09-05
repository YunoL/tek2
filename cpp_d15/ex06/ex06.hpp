#ifndef EX06_HPP_
#define EX06_HPP_

#include <string>
#include <sstream>
#include <iostream>

template<typename X>
std::string print(X) {
	return std::string("???");
}

template<>
std::string print(int a) {
	std::stringstream os;
	os << a;
	return std::string("int:") + os.str();
}

template<>
std::string print(float a) {
	std::stringstream os;
	os << a;
	return std::string("float:") + os.str() + "f";
}

template<>
std::string print(std::string a) {
	return std::string("string:\"") + a + "\"";
}

template<typename X, typename T = X>
class Tuple {
public:
	X a;
	T b;
	std::string toString() const {
		return std::string("[TUPLE [") + print(a) + "] [" + print(b) + "]]";
	}
};

#endif
