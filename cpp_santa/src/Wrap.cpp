//
// Wrap.cpp for wrap in /home/guillaume2.roux/rendu/my_SantaClaus
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
//
// Started on  Sat Jan 14 10:31:09 2017 Guillaume Roux
// Last update Sun Jan 15 00:53:50 2017 Valentin Pichard
//

#include "Wrap.hh"

Wrap::Wrap(std::string const & name, std::string const & type)
  : Object(name, "wrap"), _obj(NULL), _isOpen(false), _type(type) {
}

Wrap::~Wrap() {}

bool Wrap::isEmpty() const {
  return !this->_obj;
}

bool Wrap::isOpen() const {
  return this->_isOpen;
}

Object* Wrap::takeWrap() {
  if (!this->_obj)
    return NULL;
  Object *obj = this->_obj;

  this->_obj = NULL;
  this->_isOpen = true;
  std::cout << "whistles while working" << std::endl;
  return obj;
}

void Wrap::openMe() {
  this->_isOpen = true;
}

void Wrap::wrapMeThat(Object *obj) {
  if (this->_obj)
    return;
  std::cout << "tuuuut tuuut tuut" << std::endl;
  this->_obj = obj;
}

std::string Wrap::getType() const {
  return this->_type;
}
