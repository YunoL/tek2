//
// LittlePony.hh for littlepony in /home/guillaume2.roux/rendu/my_SantaClaus
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
//
// Started on  Sat Jan 14 09:03:45 2017 Guillaume Roux
// Last update Sat Jan 14 13:39:35 2017 Valentin Pichard
//

#ifndef LITTLEPONY_HH_
#define LITTLEPONY_HH_

#include "Toy.hh"

class LittlePony : public Toy {
public:
  LittlePony(std::string const & name);
  ~LittlePony();
  void isTaken();
};

#endif
