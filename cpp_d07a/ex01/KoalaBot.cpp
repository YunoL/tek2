//
// KoalaBot.cpp for koalabot in /home/guillaume2.roux/rendu/cpp_d07a/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Tue Jan 10 17:42:29 2017 Guillaume Roux
// Last update Tue Jan 10 17:42:30 2017 Guillaume Roux
//

#include "KoalaBot.h"

KoalaBot::KoalaBot(std::string serial)
{
	this->_serial = serial;
}
	
KoalaBot::~KoalaBot()
{

}

void	KoalaBot::setParts(Arms& arms)
{
	this->_arms = arms;
}

void	KoalaBot::setParts(Legs& legs)
{
	this->_legs = legs;
}

void	KoalaBot::setParts(Head& head)
{
	this->_head = head;
}

void	KoalaBot::swapParts(Arms& arms)
{
	setParts(arms);
}

void	KoalaBot::swapParts(Legs& legs)
{
	setParts(legs);
}

void	KoalaBot::swapParts(Head& head)
{
	setParts(head);
}

void	KoalaBot::informations() const
{
	std::cout << "[KoalaBot] " << this->_serial << std::endl;
	this->_arms.informations();
	this->_legs.informations();
	this->_head.informations();
}

bool	KoalaBot::status() const
{
	if (this->_arms.isFunctionnal() == true && this->_legs.isFunctionnal() == true && this->_head.isFunctionnal() == true)
		return (true);
	return (false);
}