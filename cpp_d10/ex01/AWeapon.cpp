//
// AWeapon.cpp for aweapon in /home/guillaume2.roux/rendu/cpp_d10/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 10:12:44 2017 Guillaume Roux
// Last update Fri Jan 13 10:12:45 2017 Guillaume Roux
//

#include "AWeapon.hh"
AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	this->_name = name;
	this->_apcost = apcost;
	this->_damage = damage;
}

AWeapon::~AWeapon()
{

}

std::string	const & AWeapon::getName() const
{
	return (this->_name);
}

int	AWeapon::getAPCost() const
{
	return this->_apcost;
}
	
int AWeapon::getDamage() const
{
	return this->_damage;
}

void	AWeapon::attack() const
{

}