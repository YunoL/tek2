//
// Toy.cpp for toy in /home/guillaume2.roux/rendu/my_SantaClaus
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
//
// Started on  Sat Jan 14 10:08:38 2017 Guillaume Roux
// Last update Sun Jan 15 00:48:46 2017 Valentin Pichard
//

#include "Toy.hh"

Toy::Toy(std::string const & name, std::string const & type)
  : Object(name, "toy"), _type(type) {
}

Toy::~Toy() {}

std::string Toy::getType() const {
  return this->_type;
}
