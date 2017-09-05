//
// Tactical.hh for tactical in /home/guillaume2.roux/rendu/cpp_d10/ex02
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 11:44:36 2017 Guillaume Roux
// Last update Fri Jan 13 11:44:37 2017 Guillaume Roux
//

#ifndef TACTICALMARINE_H_
#define TACTICALMARINE_H_

#include <iostream>
#include "ISpaceMarine.hh"

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const & marine);
	virtual ~TacticalMarine();
	virtual ISpaceMarine *clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;
};

#endif