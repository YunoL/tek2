//
// AMateria.cpp for amateria in /home/guillaume2.roux/rendu/cpp_d10/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 14:06:10 2017 Guillaume Roux
// Last update Fri Jan 13 14:06:11 2017 Guillaume Roux
//

#include "AMateria.hh"

AMateria::AMateria(std::string const & type) : _type(type), xp_(0)
{

}

AMateria::~AMateria()
{

}

std::string const & AMateria::getType() const
{
	return this->_type;
}

unsigned int AMateria::getXP() const
{
	return this->xp_;
}

void	AMateria::use(ICharacter& target)
{
	this->xp_ += 10;
	effect(target);
}

void AMateria::effect(ICharacter& target)
{
	(void) target;
}
