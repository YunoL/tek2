//
// SuperMutant.cpp for supermutant in /home/guillaume2.roux/rendu/cpp_d10/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 10:46:01 2017 Guillaume Roux
// Last update Fri Jan 13 10:46:02 2017 Guillaume Roux
//

#include "SuperMutant.hh"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
	damage -= 3;
	if (damage < 0)
		return;
	this->_hp -= damage;
	if (this->_hp < 0)
		this->_hp = 0;
}