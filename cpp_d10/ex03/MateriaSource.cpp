//
// MateriaSource.cpp for materiasource in /home/guillaume2.roux/rendu/cpp_d10/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 14:56:42 2017 Guillaume Roux
// Last update Fri Jan 13 14:56:43 2017 Guillaume Roux
//

#include "MateriaSource.hh"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (materia)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (!this->_inventory[i])
			{
				this->_inventory[i] = materia;
				return;
			}
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			return this->_inventory[i]->clone();
	}
	return NULL;
}