#ifndef EX03_HPP_
#define EX03_HPP_

#include <iostream>

template<typename X>
void foreach(const X* array, void (func)(const X&), int size)
{
  for (int i = 0; i < size; i++) {
    func(array[i]);
  }
}

template<typename X>
void print(const X& val)
{
  std::cout << val << '\n';
}

#endif
