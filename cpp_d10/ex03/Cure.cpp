//
// Cure.cpp for cure in /home/guillaume2.roux/rendu/cpp_d10/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 14:25:29 2017 Guillaume Roux
// Last update Fri Jan 13 14:25:30 2017 Guillaume Roux
//

#include "Cure.hh"

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(AMateria const & cure) : AMateria("cure")
{
	this->xp_ = cure.getXP();
}

Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::effect(ICharacter & target) 
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}