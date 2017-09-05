//
// Teddy.hh for teddy in /home/guillaume2.roux/rendu/my_SantaClaus
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
//
// Started on  Sat Jan 14 09:07:03 2017 Guillaume Roux
// Last update Sat Jan 14 13:40:58 2017 Valentin Pichard
//

#ifndef TEDDY_HH_
#define TEDDY_HH_

#include <iostream>
#include "Toy.hh"

class Teddy : public Toy {
public:
  Teddy(std::string const & name);
  ~Teddy();
  void isTaken();
};

#endif
