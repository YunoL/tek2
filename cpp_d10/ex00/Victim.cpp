//
// Victim.cpp for victim in /home/guillaume2.roux/rendu/cpp_d10/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 09:22:45 2017 Guillaume Roux
// Last update Fri Jan 13 09:22:46 2017 Guillaume Roux
//

#include "Victim.hh"

Victim::Victim(std::string name)
{
	this->_name = name;
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
}

std::string	Victim::getName() const
{
	return this->_name;
}

void	Victim::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream & operator<<(std::ostream & os, Victim const & slave)
{
	return (os << "I'm " << slave.getName() << " and i like otters !" << std::endl);
}