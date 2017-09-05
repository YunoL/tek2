//
// Federation.cpp for Federation in /home/guillaume2.roux/rendu/cpp_d07m/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Tue Jan 10 11:58:09 2017 Guillaume Roux
// Last update Tue Jan 10 11:58:13 2017 Guillaume Roux
//

#include <iostream>
#include "Federation.hh"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
	this->_length = length;
	this->_width = width;
	this->_name = name;
	this->_maxWarp = maxWarp;
	std::cout << "The ship USS " << this->_name << " has been finished. It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
	std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship(void)
{

}

void	Federation::Starfleet::Ship::setupCore(WarpSystem::Core*	core)
{
	this->_core = core;
	std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void	Federation::Starfleet::Ship::checkCore(void)
{
	std::string	tmp = "unstable";

	if (this->_core->checkReactor()->isStable() == true)
		tmp = "stable";
	std::cout << "USS " << this->_name << ": The core is " << tmp << " at the time." << std::endl;
}

void	Federation::Starfleet::Ship::promote(Captain* captain)
{
	std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
	this->_length = length;
	this->_width = width;
	this->_name = name;
	this->_maxWarp = 1;
	std::cout << "The independant ship " << this->_name << " just finished its construction. It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}

Federation::Ship::~Ship(void)
{

}

void	Federation::Ship::setupCore(WarpSystem::Core*	core)
{
	this->_core = core;
	std::cout << this->_name << ": The core is set." << std::endl;
}

void	Federation::Ship::checkCore(void)
{
	std::string	tmp = "unstable";

	if (this->_core->checkReactor()->isStable() == true)
		tmp = "stable";
	std::cout << this->_name << ": The core is " << tmp << " at the time." << std::endl;	
}

Federation::Starfleet::Captain::Captain(std::string name)
{
	this->_name = name;
}

Federation::Starfleet::Captain::~Captain(void)
{

}

std::string	Federation::Starfleet::Captain::getName(void)
{
	return(this->_name);
}

int	Federation::Starfleet::Captain::getAge(void)
{
	return (this->_age);
}

void	Federation::Starfleet::Captain::setAge(int age)
{
	this->_age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
	this->_name = name;
	std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{

}