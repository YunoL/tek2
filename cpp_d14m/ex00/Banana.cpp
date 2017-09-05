#include "Banana.h"

Banana::Banana() : Fruit("banana", 5)
{}

Banana::~Banana()
{}

std::string const &Banana::getName() const
{
  return this->_name;
}
