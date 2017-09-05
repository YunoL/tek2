//
// Paladin.cpp for paladin in /home/guillaume2.roux/rendu/cpp_d09/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Thu Jan 12 16:26:04 2017 Guillaume Roux
// Last update Thu Jan 12 16:26:05 2017 Guillaume Roux
//

#include "Paladin.hh"
#include <iostream>

Paladin::Paladin(const std::string &name, int lvl) : Character(name, lvl), Warrior(name, lvl), Priest(name, lvl)
{
	this->_name = name;
	this->_level = lvl;
	this->_pv = 100;
	this->_power = 100;
	this->_strenght = 9;
	this->_stamina = 10;
	this->_intelligence = 10;
	this->_spirit = 10;
	this->_agility = 2;
	this->Range = Character::CLOSE;
	this->weaponName = std::string ("hammer");
	std::cout << "the light falls on " << this->_name << std::endl;
}

Paladin::Paladin::~Paladin()
{

}

int Paladin::CloseAttack()
{
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

int	Paladin::RangeAttack()
{
	int damage = 0;
	if (this->_power >= 25)
	{
		this->_power -= 25;
		damage = 20 + this->_spirit;
		std::cout << this->_name << " launches a fire ball" << std::endl;
	}
	else
		std::cout << this->_name << " out of power" << std::endl;
	return (damage);
}
	
void	Paladin::Heal()
{
	if (this->_power >= 10)
	{
		this->_power -= 10;
		this->_pv += 70;
		if (this->_pv > 100)
			this->_pv = 100;
		std::cout << this->_name << " casts a little heal spell" << std::endl;
	}
	else
		std::cout << this->_name << " out of power" << std::endl;
}

void	Paladin::RestorePower()
{
	this->_power = 100;
	std::cout << this->_name << " eats" << std::endl;
}

int 	Paladin::Intercept()
{
	if (this->_power >= 10)
	{
		this->_power -= 10;
		std::cout << this->_name << " intercepts" << std::endl;
		this->Range = Character::CLOSE;
	}
	else
		std::cout << this->_name << " out of power" << std::endl;
	return 0;
}