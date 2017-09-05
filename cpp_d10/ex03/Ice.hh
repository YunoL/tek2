//
// Ice.hh for ice in /home/guillaume2.roux/rendu/cpp_d10/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 14:22:09 2017 Guillaume Roux
// Last update Fri Jan 13 14:22:10 2017 Guillaume Roux
//

#ifndef ICE_H_
#define ICE_H_

#include "AMateria.hh"

class Ice : public AMateria
{
public:
	Ice();
	Ice(AMateria const & ice);
	virtual ~Ice();
	virtual AMateria* clone() const;
	virtual void effect(ICharacter & target);
};

#endif