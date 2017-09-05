//
// Character.hh for character in /home/guillaume2.roux/rendu/cpp_d10/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 10:56:53 2017 Guillaume Roux
// Last update Fri Jan 13 10:56:53 2017 Guillaume Roux
//

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>
#include "AWeapon.hh"
#include "AEnemy.hh"

class Character
{
public:
	Character(std::string const & name);
	virtual ~Character();
	void	recoverAP();
	void	equip(AWeapon* weapon);
	void	attack(AEnemy* ennemy);
	std::string	const & getName() const;
	int	getAP() const;
	AWeapon *getWeapon() const;
protected:
	std::string _name;
	int	_hp;
	int _ap;
	AWeapon	*_weapon;

};

std::ostream & operator<<(std::ostream & os, Character const & perso);

#endif