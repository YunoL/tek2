#ifndef BUZZ_H_
#define BUZZ_H_

#include <iostream>
#include "Toy.h"

class Buzz : public Toy {
public:
  Buzz(std::string const &name, std::string const &filename = "buzz.txt");
  virtual ~Buzz();
  virtual void speak(std::string const & message);
};

#endif
