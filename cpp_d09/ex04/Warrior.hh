//
// Warrior.hh for warrior in /home/guillaume2.roux/rendu/cpp_d09/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Thu Jan 12 11:43:45 2017 Guillaume Roux
// Last update Thu Jan 12 11:43:46 2017 Guillaume Roux
//

#ifndef WARRIOR_H_
#define WARRIOR_H_

#include <iostream>
#include "Character.hh"

class Warrior : virtual public Character
{
public:
	Warrior(const std::string &name, int lvl);
	~Warrior();
	int 	CloseAttack();
	int 	RangeAttack();
protected:
	std::string weaponName;
};

#endif