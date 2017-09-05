//
// Priest.hh for priest in /home/guillaume2.roux/rendu/cpp_d09/ex02
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Thu Jan 12 16:01:37 2017 Guillaume Roux
// Last update Thu Jan 12 16:01:41 2017 Guillaume Roux
//

#ifndef PRIEST_H_
#define PRIEST_H_

#include "Mage.hh"

class Priest : public Mage
{
public:
	Priest(const std::string &name, int lvl);
	~Priest();
	int 	CloseAttack();
	void		Heal();
};

#endif