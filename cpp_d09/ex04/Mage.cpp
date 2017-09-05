//
// Mage.cpp for mage in /home/guillaume2.roux/rendu/cpp_d09/ex02
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Thu Jan 12 15:26:26 2017 Guillaume Roux
// Last update Thu Jan 12 15:26:27 2017 Guillaume Roux
//

#include "Mage.hh"

Mage::Mage(const std::string &name, int lvl) : Character(name, lvl)
{
	this->_name = name;
	this->_level = lvl;
	this->_pv = 100;
	this->_power = 100;
	this->_strenght = 6;
	this->_stamina = 6;
	this->_intelligence = 12;
	this->_spirit = 11;
	this->_agility = 7;
	this->Range = Character::CLOSE;
	std::cout << this->_name << " teleported" << std::endl;
}

Mage::~Mage()
{

}

int	Mage::CloseAttack()
{
	int damage = 0;
	if (this->_power >= 10)
	{
		this->_power -= 10;
		std::cout << this->_name << " blinks" << std::endl;
	}
	else
		std::cout << this->_name << " out of power" << std::endl;
	this->Range = RANGE;
	return (damage);
}

int	Mage::RangeAttack()
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

void	Mage::RestorePower()
{
	this->_power += 50 + this->_intelligence;
	if (this->_power >= 100)
		this->_power = 100;
	std::cout << this->_name << " takes a mana potion" << std::endl;
}