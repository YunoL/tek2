//
// Warrior.cpp for warrior in /home/guillaume2.roux/rendu/cpp_d09/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Thu Jan 12 11:43:52 2017 Guillaume Roux
// Last update Thu Jan 12 11:43:53 2017 Guillaume Roux
//

#include <iostream>
#include "Warrior.hh"

Warrior::Warrior(const std::string &name, int lvl) : Character(name, lvl)
{
	this->_name = name;
	this->_level = lvl;
	this->_pv = 100;
	this->_power = 100;
	this->_strenght = 12;
	this->_stamina = 12;
	this->_intelligence = 6;
	this->_spirit = 5;
	this->_agility = 7;
	this->Range = Character::CLOSE;
	this->weaponName = std::string ("hammer");
	std::cout << "I'm " << this->_name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{

}

int 	Warrior::CloseAttack()
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

int 	Warrior::RangeAttack()
{
	int damage = 0;
	if (this->_power >= 10)
	{
		this->_power -= 10;
		std::cout << this->_name << " intercepts" << std::endl;
	}
	else
		std::cout << this->_name << " out of power" << std::endl;
	this->Range = CLOSE;
	return (damage);
}