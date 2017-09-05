//
// Paladin.hh for paladin in /home/guillaume2.roux/rendu/cpp_d09/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Thu Jan 12 16:25:49 2017 Guillaume Roux
// Last update Thu Jan 12 16:25:50 2017 Guillaume Roux
//

#ifndef PALADIN_H_
#define PALADIN_H_

#include "Warrior.hh"
#include "Priest.hh"

class Paladin : public Warrior, public Priest
{
public:
	Paladin(const std::string &name, int lvl);
	~Paladin();
	int CloseAttack();
	int	RangeAttack();
	void	Heal();
	void	RestorePower();
	int		Intercept();
};

#endif