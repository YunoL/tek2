//
// carrier.cpp for carrier in /home/guillaume2.roux/rendu/cpp_d08/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Wed Jan 11 18:31:04 2017 Guillaume Roux
// Last update Wed Jan 11 18:31:05 2017 Guillaume Roux
//

#include "carrier.hh"
#include <iostream>

Carrier::Carrier(std::string Id) : Energy(300), Attack(100), Toughness(90)
{
	this->Droids = new Droid *[5];
	for (int i = 0; i < 5; ++i)
		this->Droids[i] = NULL;
}

Carrier::~Carrier()
{

}