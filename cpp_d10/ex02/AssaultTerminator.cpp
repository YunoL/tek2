//
// AssaultTerminator.cpp for assaultterminator in /home/guillaume2.roux/rendu/cpp_d10/ex02
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 11:45:38 2017 Guillaume Roux
// Last update Fri Jan 13 11:45:39 2017 Guillaume Roux
//

#include "AssaultTerminator.hh"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & marine)
{
	(void) marine;
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back ..." << std::endl;
}

ISpaceMarine *AssaultTerminator::clone() const
{
	return new AssaultTerminator (*this);
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;	
}

void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;	
}