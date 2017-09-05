//
// Hunter.cpp for hunter in /home/guillaume2.roux/rendu/cpp_d09/ex04
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Thu Jan 12 17:41:55 2017 Guillaume Roux
// Last update Thu Jan 12 17:41:56 2017 Guillaume Roux
//

#include "Hunter.hh"

Hunter::Hunter(const std::string &name, int lvl) : Character(name, lvl), Warrior(name, lvl)
{
	this->_name = name;
	this->_level = lvl;
	this->_pv = 100;
	this->_power = 100;
	this->_strenght = 9;
	this->_stamina = 9;
	this->_intelligence = 5;
	this->_spirit = 6;
	this->_agility = 24;
	this->Range = Character::CLOSE;
	this->weaponName = std::string ("sword");
	std::cout << this->_name << " is born from a tree" << std::endl;
}

Hunter::~Hunter()
{

}

int 	Hunter::CloseAttack()
{
	this->weaponName = std::string ("sword");
	int damage = 0;
	if (this->_power >= 30)
	{
		this->_power -= 30;
		damage = 20 + this->_strenght;
		std::cout << this->_name << " strikes with his " << this->weaponName << std::endl;
	}
	else
		std::cout << this->_name << " out of power" << std::endl;
	return (damage);
}

int 	Hunter::RangeAttack()
{
	int damage = 0;
	if (this->_power >= 25)
	{
		this->_power -= 25;
		damage = 20 + this->_agility;
		std::cout << this->_name << " uses his bow";
	}
	else
		std::cout << this->_name << " out of power" << std::endl;
	return (damage);
}

void	Hunter::Heal()
{
	this->_pv += 50;
	if (this->_pv > 100)
		this->_pv = 100;
	std::cout << this->_name << " takes a potion" << std::endl;
}

void	Hunter::RestorePower()
{
	this->_power = 100;
	std::cout << this->_name << " meditates" << std::endl;
}