//
// Object.cpp for object in /home/guillaume2.roux/rendu/my_SantaClaus
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
//
// Started on  Sat Jan 14 10:10:17 2017 Guillaume Roux
// Last update Sun Jan 15 00:52:58 2017 Valentin Pichard
//

#include "Object.hh"

Object::Object(std::string const & name, std::string const & type) {
  this->_name = name;
  this->_type = type;
}

Object::~Object() {}

std::string	const & Object::getName() const {
  return this->_name;
}

std::string      Object::getType() const {
  return this->_type;
}


std::ostream & operator<<(std::ostream & os, Object const *obj) {
  os << obj->getName();
  return os;
}
