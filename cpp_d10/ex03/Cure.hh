//
// Cure.hh for cure in /home/guillaume2.roux/rendu/cpp_d10/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 14:25:25 2017 Guillaume Roux
// Last update Fri Jan 13 14:25:25 2017 Guillaume Roux
//

#ifndef CURE_H_
#define CURE_H_

#include "AMateria.hh"

class Cure : public AMateria
{
public:
	Cure();
	Cure(AMateria const & cure);
	virtual ~Cure();
	virtual AMateria* clone() const;
	virtual void effect(ICharacter & target);
};

#endif