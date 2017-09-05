//
// Hunter.hh for hunter in /home/guillaume2.roux/rendu/cpp_d09/ex04
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Thu Jan 12 17:42:01 2017 Guillaume Roux
// Last update Thu Jan 12 17:42:02 2017 Guillaume Roux
//

#ifndef HUNTER_H_
#define HUNTER_H_

#include "Warrior.hh"

class Hunter : protected Warrior
{
public:
	Hunter(const std::string &name, int lvl);
	~Hunter();
	int 	CloseAttack();
	int 	RangeAttack();
	void	Heal();
	void	RestorePower();
};

#endif