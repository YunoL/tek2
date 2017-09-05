//
// PowerFist.cpp for powerfist in /home/guillaume2.roux/rendu/cpp_d10/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 10:35:05 2017 Guillaume Roux
// Last update Fri Jan 13 10:35:06 2017 Guillaume Roux
//

#include "PowerFist.hh"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{

}

PowerFist::~PowerFist()
{

}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}