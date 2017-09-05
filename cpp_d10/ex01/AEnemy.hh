//
// AEnemy.hh for AEnemy in /home/guillaume2.roux/rendu/cpp_d10/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 10:39:21 2017 Guillaume Roux
// Last update Fri Jan 13 10:39:22 2017 Guillaume Roux
//

#ifndef AENEMY_H_
#define AENEMY_H_

#include <iostream>

class AEnemy
{
public:
	AEnemy(int hp, std::string const & type);
	virtual ~AEnemy();
	std::string	const & getType() const;
	int getHP() const;
	virtual void takeDamage(int damage);
protected:
	std::string	_type;
	int	_hp;
};

#endif