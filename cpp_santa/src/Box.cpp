//
// Box.cpp for box in /home/guillaume2.roux/rendu/my_SantaClaus
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
//
// Started on  Sat Jan 14 10:48:53 2017 Guillaume Roux
// Last update Sat Jan 14 13:38:48 2017 Valentin Pichard
//

#include "Box.hh"

Box::Box(std::string const & name) : Wrap(name, "box") {}

Box::~Box() {}

void Box::wrapMeThat(Object* obj) {
  if (this->_isOpen) {
      Wrap::wrapMeThat(obj);
      this->_isOpen = false;
    }
}

void Box::closeMe() {
  this->_isOpen = false;
}
