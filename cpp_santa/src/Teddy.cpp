//
// Teddy.cpp for teddy in /home/guillaume2.roux/rendu/my_SantaClaus
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
//
// Started on  Sat Jan 14 09:16:21 2017 Guillaume Roux
// Last update Sat Jan 14 13:40:50 2017 Valentin Pichard
//

#include "Teddy.hh"

Teddy::Teddy(std::string const & name) : Toy(name, "teddy") {}

Teddy::~Teddy() {}

void Teddy::isTaken() {
  std::cout << "gra hu" << std::endl;
}
