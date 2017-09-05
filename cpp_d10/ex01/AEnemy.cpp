//
// AEnemy.cpp for AEnemy in /home/guillaume2.roux/rendu/cpp_d10/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 10:39:28 2017 Guillaume Roux
// Last update Fri Jan 13 10:39:29 2017 Guillaume Roux
//

#include "AEnemy.hh"

AEnemy::AEnemy(int hp, std::string const & type)
{
	this->_hp = hp;
	this->_type = type;
}

AEnemy::~AEnemy()
{

}

std::string	const & AEnemy::getType() const
{
	return this->_type;
}

int AEnemy::getHP() const
{
	return this->_hp;
}

void AEnemy::takeDamage(int damage)
{
	if (damage < 0)
		return;
	this->_hp -= damage;
}