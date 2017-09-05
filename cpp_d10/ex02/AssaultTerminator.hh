//
// AssaultTerminator.hh for assaultterminator in /home/guillaume2.roux/rendu/cpp_d10/ex02
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 11:45:31 2017 Guillaume Roux
// Last update Fri Jan 13 11:45:32 2017 Guillaume Roux
//

#ifndef ASSAULTTERMINATOR_H_
#define ASSAULTTERMINATOR_H_

#include <iostream>
#include "ISpaceMarine.hh"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(AssaultTerminator const & marine);
	virtual ~AssaultTerminator();
	virtual ISpaceMarine *clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;
};

#endif