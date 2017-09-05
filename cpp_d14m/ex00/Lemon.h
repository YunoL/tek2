#ifndef LEMON_H_
#define LEMON_H_

#include <iostream>
#include "Fruit.h"

class Lemon : public Fruit {
public:
  Lemon();
  virtual ~Lemon();
  virtual std::string const &getName() const;
};

#endif
