//
// Toy.hh for toy in /home/guillaume2.roux/rendu/my_SantaClaus
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
//
// Started on  Sat Jan 14 09:04:05 2017 Guillaume Roux
// Last update Sun Jan 15 00:50:17 2017 Valentin Pichard
//

#ifndef TOY_HH_
#define TOY_HH_

#include <iostream>
#include "Object.hh"

class Toy : public Object {
public:
  Toy(std::string const & name, std::string const & type);
  virtual ~Toy();

  virtual void isTaken() = 0;
  std::string getType() const;
private:
  std::string _type;
};

#endif
