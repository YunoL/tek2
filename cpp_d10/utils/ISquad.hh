//
// ISquad.hh for isquad in /home/guillaume2.roux/rendu/cpp_d10/ex02
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 13:03:05 2017 Guillaume Roux
// Last update Fri Jan 13 13:03:07 2017 Guillaume Roux
//

#ifndef ISQUAD_H_
#define ISQUAD_H_

#include "ISpaceMarine.hh"

class ISquad
{
public:
	virtual ~ISquad() {};
	virtual int getCount() const = 0;
	virtual ISpaceMarine* getUnit(int) = 0;
	virtual int push(ISpaceMarine*) = 0;
};

#endif 