//
// Box.hh for box in /home/guillaume2.roux/rendu/my_SantaClaus
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
//
// Started on  Sat Jan 14 10:49:00 2017 Guillaume Roux
// Last update Sat Jan 14 13:38:55 2017 Valentin Pichard
//

#ifndef BOX_HH_
#define BOX_HH_

#include <iostream>
#include "Wrap.hh"

class Box : public Wrap {
public:
  Box(std::string const & name);
  ~Box();
  void	closeMe();
  void	wrapMeThat(Object* obj);
};

#endif
