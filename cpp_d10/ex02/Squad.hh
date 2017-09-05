//
// Squad.hh for squad in /home/guillaume2.roux/rendu/cpp_d10/ex02
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 11:44:16 2017 Guillaume Roux
// Last update Fri Jan 13 11:44:17 2017 Guillaume Roux
//

#ifndef SQUAD_H_
#define SQUAD_H_

#include <iostream>
#include "ISquad.hh"
#include "ISpaceMarine.hh"

class Squad : public ISquad
{
public:
	Squad();
	Squad(Squad const & squad);
	virtual ~Squad();
	int getCount() const;
	ISpaceMarine*	getUnit(int pos);
	int push(ISpaceMarine* marine);
	Squad & operator=(Squad const & squad);
protected:
	int _count;
	int	_size;
	ISpaceMarine	**_array;
	void resize();
};

#endif