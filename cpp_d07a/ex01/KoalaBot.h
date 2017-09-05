/*
** KoalaBot.h for koalabot in /home/guillaume2.roux/rendu/cpp_d07a/ex01
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Tue Jan 10 17:42:37 2017 Guillaume Roux
** Last update Tue Jan 10 17:42:37 2017 Guillaume Roux
*/

#ifndef KOALABOT_H_
#define KOALABOT_H_

#include <iostream>
#include "Parts.h"

class KoalaBot
{
public:
	KoalaBot(std::string serial = "Bob-01");
	~KoalaBot();
	void	setParts(Arms& arms);
	void	setParts(Legs& legs);
	void	setParts(Head& head);
	void	swapParts(Arms& arms);
	void	swapParts(Legs& legs);
	void	swapParts(Head& head);
	void	informations() const;
	bool	status() const;
private:
	std::string	_serial;
	Arms	_arms;
	Legs	_legs;
	Head	_head;
};

#endif