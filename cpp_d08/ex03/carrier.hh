//
// carrier.hh for carrier in /home/guillaume2.roux/rendu/cpp_d08/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Wed Jan 11 18:30:55 2017 Guillaume Roux
// Last update Wed Jan 11 18:30:56 2017 Guillaume Roux
//

#ifndef CARRIER_H_
#define CARRIER_H_

#include <iostream>

class Carrier
{
public:
	Carrier(std::string Id = "");
	~Carrier();
private:
	std::string	Id;
	size_t	Energy;
	size_t const	Attack;
	size_t const	Toughness;
	size_t	Speed;
	Droid**	Droids;
};

#endif