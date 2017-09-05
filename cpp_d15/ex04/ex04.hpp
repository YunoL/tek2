#ifndef EX04_HPP_
#define EX04_HPP_

#include <iostream>

template<typename T>
bool  equal(const T& a, const T& b);

template<typename X>
class Tester {
public:
  bool  equal(const X& a, const X& b);
};

#endif
