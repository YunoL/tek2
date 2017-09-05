//
// Borg.cpp for borg in /home/guillaume2.roux/rendu/cpp_d07m/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Tue Jan 10 13:34:04 2017 Guillaume Roux
// Last update Tue Jan 10 13:34:05 2017 Guillaume Roux
//

#include <iostream>
#include "Borg.hh"
#include "WarpSystem.hh"

Borg::Ship::Ship(int weaponFrequency, short repair)
{
	this->_side = 300;
	this->_maxWarp = 9;
	this->_home = UNICOMPLEX;
	this->_location = this->_home;
	this->_shield = 100;
	this->_weaponFrequency = weaponFrequency;
	this->_repair = repair;
	std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
	std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
	std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship(void)
{

}

void	Borg::Ship::setupCore(WarpSystem::Core*	core)
{
	this->_core = core;
}

void	Borg::Ship::checkCore(void)
{
	std::string	tmp = "Critical failure imminent.";

	if (this->_core->checkReactor()->isStable() == true)
		tmp = "Everything is in order.";
	std::cout << tmp << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
	if (warp <= this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable())
	{
		this->_location = d;
		return (true);
	}
	return (false);
}

bool Borg::Ship::move(int warp)
{
	return (move(warp, this->_home));
}

bool Borg::Ship::move(Destination d)
{
	return (move(this->_maxWarp, d));
}

bool Borg::Ship::move()
{
	return (move(this->_maxWarp, this->_home));
}

int	Borg::Ship::getShield(void)
{
	return (this->_shield);
}

void	Borg::Ship::setShield(int value)
{
	this->_shield = value;
}

int	Borg::Ship::getWeaponFrequency()
{
	return (this->_weaponFrequency);
}

void	Borg::Ship::setWeaponFrequency(int value)
{
	this->_weaponFrequency = value;
}
		
short	Borg::Ship::getRepair()
{
	return (this->_repair);
}

void	Borg::Ship::setRepair(short value)
{
	this->_repair = value;
}

void	Borg::Ship::fire(Federation::Starfleet::Ship*	ennemy)
{
	ennemy->setShield(ennemy->getShield() - this->getWeaponFrequency());
	std::cout << "Firing on target with " << this->getWeaponFrequency() << "GW frequency." << std::endl;
}
	
void	Borg::Ship::fire(Federation::Ship*	ennemy)
{
	ennemy->getCore()->checkReactor()->setStability(false);
	std::cout << "Firing on target with " << this->getWeaponFrequency() << "GW frequency." << std::endl;
}

void	Borg::Ship::repair()
{
	if (this->_repair > 0)
	{
		this->_repair--;
		this->_shield = 100;
		std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
	}
	else
		std::cout << "Energy cells depleted, shield weakening." << std::endl;
}