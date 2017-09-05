//
// ICharacter.hh for icharacter in /home/guillaume2.roux/rendu/cpp_d10/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 14:36:08 2017 Guillaume Roux
// Last update Fri Jan 13 14:36:09 2017 Guillaume Roux
//

#ifndef ICHARACTER_H_
#define ICHARACTER_H_

class ICharacter;

#include "AMateria.hh"

class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual	void unequip(int idx) = 0;
	virtual	void use(int idx, ICharacter& target) = 0;
};

#endif