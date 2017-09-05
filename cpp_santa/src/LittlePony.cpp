//
// LittlePony.cpp for littlepony in /home/guillaume2.roux/rendu/my_SantaClaus
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
//
// Started on  Sat Jan 14 09:16:11 2017 Guillaume Roux
// Last update Sat Jan 14 13:39:31 2017 Valentin Pichard
//

#include "LittlePony.hh"

LittlePony::LittlePony(std::string const & name) : Toy(name, "littlepony") {}

LittlePony::~LittlePony() {}

void LittlePony::isTaken() {
  std::cout << "yo man" << std::endl;
}
