#ifndef WOODY_H_
#define WOODY_H_

#include "Toy.h"
#include <iostream>

class Woody : public Toy {
public:
  Woody(std::string const &name, std::string const &filename = "woody.txt");
  virtual ~Woody();
};

#endif
