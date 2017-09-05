//
// IMateriaSource.hh for imateriasource in /home/guillaume2.roux/rendu/cpp_d10/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 15:03:49 2017 Guillaume Roux
// Last update Fri Jan 13 15:03:49 2017 Guillaume Roux
//

#ifndef IMATERIASOURCE_H_
#define IMATERIASOURCE_H_

#include "AMateria.hh"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual	void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif