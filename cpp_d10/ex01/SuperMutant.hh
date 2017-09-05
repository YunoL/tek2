//
// SuperMutant.hh for supermutant in /home/guillaume2.roux/rendu/cpp_d10/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 10:45:56 2017 Guillaume Roux
// Last update Fri Jan 13 10:45:57 2017 Guillaume Roux
//

#ifndef SUPERMUTANT_H_
#define SUPERMUTANT_H_

#include "AEnemy.hh"

class SuperMutant : public AEnemy
{
public:
	SuperMutant();
	virtual ~SuperMutant();
	virtual void takeDamage(int damage);
};

#endif