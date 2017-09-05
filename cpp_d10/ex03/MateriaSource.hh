//
// MateriaSource.hh for materiasource in /home/guillaume2.roux/rendu/cpp_d10/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 14:56:49 2017 Guillaume Roux
// Last update Fri Jan 13 14:56:50 2017 Guillaume Roux
//

#ifndef MATERIASOURCE_H_
#define MATERIASOURCE_H_

#include <iostream>
#include "IMateriaSource.hh"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	~MateriaSource();
	virtual	void learnMateria(AMateria* materia);
	virtual AMateria* createMateria(std::string const & type);
protected:
	AMateria* _inventory[4];
};

#endif