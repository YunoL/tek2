//
// Mage.hh for mage in /home/guillaume2.roux/rendu/cpp_d09/ex02
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Thu Jan 12 15:26:20 2017 Guillaume Roux
// Last update Thu Jan 12 15:26:20 2017 Guillaume Roux
//

#ifndef MAGE_H_
#define MAGE_H_

#include "Character.hh"

class Mage : public Character
{
public:
	Mage(const std::string &name, int lvl);
	~Mage();
	int	CloseAttack();
	int	RangeAttack();
	void	RestorePower();
};

#endif