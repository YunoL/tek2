#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

template<typename X>
const X& min(const X& a, const X& b)
{
  std::cout << "template min" << std::endl;
  if (a <= b)
    return a;
  return b;
}

int min(int a, int b)
{
  std::cout << "non-template min" << std::endl;
  if (a <= b)
    return a;
  return b;
}

template<typename X>
const X& templateMin(const X* array, int size)
{
  X& mini = const_cast<X&>(array[0]);
  for (int i = 1; i < size; i++) {
    mini = min<X>(mini, array[i]);
  }
  return mini;
}

int nonTemplateMin(int* array, int size)
{
  int mini = array[0];
  for (int i = 1; i < size; i++) {
    mini = min(mini, array[i]);
  }
  return mini;
}

#endif
