#ifndef BANANA_H_
#define BANANA_H_

#include <iostream>
#include "Fruit.h"

class Banana : public Fruit {
public:
  Banana();
  virtual ~Banana();
  virtual std::string const &getName() const;
};

#endif
