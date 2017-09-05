//
// AWeapon.hh for aweapon in /home/guillaume2.roux/rendu/cpp_d10/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 10:12:55 2017 Guillaume Roux
// Last update Fri Jan 13 10:12:56 2017 Guillaume Roux
//

#ifndef AWEAPON_H_
# define AWEAPON_H_

#include <iostream>

class AWeapon
{
public:
	AWeapon(std::string const & name, int apcost, int damage);
	virtual ~AWeapon();
	std::string	const & getName() const;
	int	getAPCost() const;
	int getDamage() const;
	virtual void	attack() const = 0;
protected:
	int _damage;
	int	_apcost;
	std::string _name;
};

#endif