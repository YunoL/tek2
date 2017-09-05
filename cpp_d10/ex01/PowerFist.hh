//
// PowerFist.hh for powerfist in /home/guillaume2.roux/rendu/cpp_d10/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 10:35:17 2017 Guillaume Roux
// Last update Fri Jan 13 10:35:18 2017 Guillaume Roux
//

#ifndef POWERFIST_H_
#define POWERFIST_H_

#include "AWeapon.hh"

class PowerFist : public AWeapon
{
public:
	PowerFist();
	virtual ~PowerFist();
	virtual void	attack() const;
};

#endif