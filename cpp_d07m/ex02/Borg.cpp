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

Borg::Ship::Ship(void)
{
	this->_side = 300;
	this->_maxWarp = 9;
	this->_home = UNICOMPLEX;
	this->_location = this->_home;
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