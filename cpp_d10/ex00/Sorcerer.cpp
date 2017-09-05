//
// Sorcerer.cpp for sorcerer in /home/guillaume2.roux/rendu/cpp_d10/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 09:04:29 2017 Guillaume Roux
// Last update Fri Jan 13 09:04:29 2017 Guillaume Roux
//

#include "Victim.hh"
#include "Sorcerer.hh"

Sorcerer::Sorcerer(std::string name, std::string title)
{
	this->_name = name;
	this->_title = title;
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
}

std::string	Sorcerer::getName() const
{
	return this->_name;
}

std::string	Sorcerer::getTitle() const
{
	return this->_title;
}

void	Sorcerer::polymorph(Victim const &slave) const
{
	slave.getPolymorphed();
}

std::ostream & operator<<(std::ostream & os, Sorcerer const & mage)
{
	return (os << "I am " << mage.getName() << ", " << mage.getTitle() << ", and I like ponies !" << std::endl);
}