//
// Character.cpp for character in /home/guillaume2.roux/rendu/cpp_d10/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 10:57:01 2017 Guillaume Roux
// Last update Fri Jan 13 10:57:02 2017 Guillaume Roux
//

#include "Character.hh"

Character::Character(std::string const & name)
{
	this->_name = name;
	this->_ap = 40;
}

Character::~Character()
{

}

int	Character::getAP() const
{
	return this->_ap;
}

AWeapon *Character::getWeapon() const
{
	return this->_weapon;
}

void	Character::recoverAP()
{
	this->_ap += 10;
	if (this->_ap > 40)
		this->_ap = 40;
}
	
void	Character::equip(AWeapon* weapon)
{
	this->_weapon = weapon;
}
	
void	Character::attack(AEnemy* ennemy)
{
	if (!this->_weapon)
		return;
	if (this->_ap >= this->_weapon->getAPCost())
	{
		this->_ap -= this->_weapon->getAPCost();
		ennemy->takeDamage(this->_weapon->getDamage());
		std::cout << this->_name << " attacks " << ennemy->getType() << " with a " << this->_weapon->getName() << std::endl;
		this->_weapon->attack();
		if (ennemy->getHP() <= 0)
			delete ennemy;
	}
}

std::string	const & Character::getName() const
{
	return this->_name;
}

std::ostream & operator<<(std::ostream & os, Character const & perso)
{
	if (perso.getWeapon())
		return (os << perso.getName() << " has " << perso.getAP() << " AP and wields a " << perso.getWeapon()->getName() << std::endl);
	return (os << perso.getName() << " has " << perso.getAP() << " AP and is unarmed" << std::endl);

}