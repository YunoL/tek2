//
// RadScorpion.cpp for radscorpion in /home/guillaume2.roux/rendu/cpp_d10/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 10:53:34 2017 Guillaume Roux
// Last update Fri Jan 13 10:53:34 2017 Guillaume Roux
//

#include "RadScorpion.hh"

RadScorpion::RadScorpion() : AEnemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}