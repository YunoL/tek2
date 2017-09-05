//
// Character.cpp for character in /home/guillaume2.roux/rendu/cpp_d10/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 14:39:41 2017 Guillaume Roux
// Last update Fri Jan 13 14:39:42 2017 Guillaume Roux
//

#include "Character.hh"

Character::Character(std::string const & name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & perso)
{
	this->_name = perso._name;
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
		if (perso._inventory[i])
			this->_inventory[i] = perso._inventory[i]->clone();
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i])
			//delete this->_inventory[i];
	}
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria * materia)
{
	if (materia)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (this->_inventory[i] == NULL)
			{
				this->_inventory[i] = materia;
				return;
			}
		}
	}
}

void Character::unequip(int index)
{
	if (index >= 0 && index < 4)
		this->_inventory[index] = NULL;
}

void Character::use(int index, ICharacter & target)
{
	if (index >= 0 && index < 4 && this->_inventory[index] != NULL)
		this->_inventory[index]->use(target);
}