//
// Victim.hh for victim in /home/guillaume2.roux/rendu/cpp_d10/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 09:22:38 2017 Guillaume Roux
// Last update Fri Jan 13 09:22:38 2017 Guillaume Roux
//

#ifndef VICTIM_H_
#define VICTIM_H_

#include <iostream>

class Victim
{
public:
	Victim(std::string name);
	~Victim();
	std::string getName() const;
	virtual void	getPolymorphed() const;
protected:
	std::string	_name;
};

std::ostream & operator<<(std::ostream & os, Victim const & slave);

#endif