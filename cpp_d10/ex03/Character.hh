//
// Character.hh for character in /home/guillaume2.roux/rendu/cpp_d10/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 14:39:32 2017 Guillaume Roux
// Last update Fri Jan 13 14:39:32 2017 Guillaume Roux
//

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>
#include "ICharacter.hh"

class Character : public ICharacter
{
public:
	Character(std::string const & name);
	Character(Character const & perso);
	~Character();
	virtual std::string const & getName() const;
	virtual void equip(AMateria * materia);
	virtual void unequip(int index);
	virtual void use(int index, ICharacter & target);
protected:
	AMateria*	_inventory[4];
	std::string	_name;
};

#endif