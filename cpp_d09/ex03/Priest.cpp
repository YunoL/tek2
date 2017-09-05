//
// Priest.cpp for priest in /home/guillaume2.roux/rendu/cpp_d09/ex02
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Thu Jan 12 16:01:54 2017 Guillaume Roux
// Last update Thu Jan 12 16:01:55 2017 Guillaume Roux
//

#include "Priest.hh"

Priest::Priest(const std::string &name, int lvl) : Character(name, lvl), Mage(name, lvl)
{
	this->_name = name;
	this->_level = lvl;
	this->_pv = 100;
	this->_power = 100;
	this->_strenght = 4;
	this->_stamina = 4;
	this->_intelligence = 42;
	this->_spirit = 21;
	this->_agility = 2;
	this->Range = Character::CLOSE;
	std::cout << this->_name << " enters in the order" << std::endl;
}

Priest::~Priest()
{

}

int 	Priest::CloseAttack()
{
	int damage = 0;
	if (this->_power >= 10)
	{
		this->_power -= 10;
		damage = 10 + this->_spirit;
		std::cout << this->_name << " uses a spirit explosion" << std::endl;
	}
	else
		std::cout << this->_name << " out of power" << std::endl;
	return (damage);
}

void	Priest::Heal()
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