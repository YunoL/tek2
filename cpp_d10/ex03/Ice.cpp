//
// Ice.cpp for ice in /home/guillaume2.roux/rendu/cpp_d10/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 14:22:14 2017 Guillaume Roux
// Last update Fri Jan 13 14:22:15 2017 Guillaume Roux
//

#include "Ice.hh"

Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(AMateria const & ice) : AMateria("ice")
{
	this->xp_ = ice.getXP();
}

Ice::~Ice()
{
	
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::effect(ICharacter & target) 
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}