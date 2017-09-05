//
// Sorcerer.hh for sorcerer in /home/guillaume2.roux/rendu/cpp_d10/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 09:04:23 2017 Guillaume Roux
// Last update Fri Jan 13 09:04:24 2017 Guillaume Roux
//

#ifndef SORCERER_H_
#define SORCERER_H_

#include "Victim.hh"
#include <iostream>

class Sorcerer
{
public:
	Sorcerer(std::string name, std::string title);
	~Sorcerer();
	std::string getName() const;
	std::string	getTitle() const;
	void	polymorph(Victim const &slave) const;
private:
	std::string	_name;
	std::string	_title;
};

std::ostream & operator<<(std::ostream & os, Sorcerer const & mage);

#endif