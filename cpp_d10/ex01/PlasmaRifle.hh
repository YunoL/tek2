//
// PlasmaRifle.hh for palsmarifle in /home/guillaume2.roux/rendu/cpp_d10/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 10:23:57 2017 Guillaume Roux
// Last update Fri Jan 13 10:23:58 2017 Guillaume Roux
//

#ifndef PLASMARIFLE_H_
#define PLASMARIFLE_H_

#include "AWeapon.hh"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle();
	virtual ~PlasmaRifle();
	virtual void	attack() const;
};

#endif