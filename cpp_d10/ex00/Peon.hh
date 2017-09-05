//
// Peon.hh for peon in /home/guillaume2.roux/rendu/cpp_d10/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 09:34:59 2017 Guillaume Roux
// Last update Fri Jan 13 09:35:00 2017 Guillaume Roux
//

#ifndef PEON_H_
#define PEON_H_

#include "Victim.hh"

class Peon : public Victim
{
public:
	Peon(std::string);
	~Peon();
	void	getPolymorphed() const;
};

#endif