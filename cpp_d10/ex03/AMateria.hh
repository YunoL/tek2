//
// AMateria.hh for amateria in /home/guillaume2.roux/rendu/cpp_d10/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 14:06:04 2017 Guillaume Roux
// Last update Fri Jan 13 14:06:05 2017 Guillaume Roux
//

#ifndef AMATERIA_H_
#define AMATERIA_H_

class AMateria;

#include <iostream>
#include "ICharacter.hh"

class AMateria
{
public:
	AMateria(std::string const & type);
	~AMateria();
	std::string const & getType() const;
	unsigned int getXP() const;
	virtual AMateria* clone() const = 0;
	virtual void	use(ICharacter& target);
	virtual void effect(ICharacter& target);
protected:
	std::string _type;
	unsigned int xp_;
};

#endif