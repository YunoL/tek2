//
// Peon.cpp for peon in /home/guillaume2.roux/rendu/cpp_d10/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 09:35:05 2017 Guillaume Roux
// Last update Fri Jan 13 09:35:06 2017 Guillaume Roux
//

#include "Peon.hh"

Peon::Peon(std::string name) : Victim(name)
{
	this->_name = name;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

void	Peon::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}