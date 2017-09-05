//
// KreogCom.cpp for kreogcom in /home/guillaume2.roux/rendu/cpp_d07a/ex02
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Tue Jan 10 18:41:45 2017 Guillaume Roux
// Last update Tue Jan 10 18:41:46 2017 Guillaume Roux
//

#include <iostream>
#include "KreogCom.h"

KreogCom::KreogCom(int x, int y, int serial) : _x(x), _y(y), m_serial(serial)
{
	this->next = 0;
	std::cout << "KreogCom " << m_serial << " initialisated" << std::endl;
}

KreogCom::~KreogCom()
{
	std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

void	KreogCom::addCom(int x, int y, int serial)
{
	KreogCom 	*new_elm = new KreogCom(x, y, serial);
	new_elm->next = this->next;
	this->next = new_elm;
}

KreogCom 	*KreogCom::getCom()
{
	if (this->next == NULL)
		return (NULL);
	return (this->next);
}

void	KreogCom::removeCom()
{
	KreogCom 	*sup;
	if (this->next != NULL)
	{
		sup = this->next;
		this->next = this->next->next;
		delete sup;
	}
}

void	KreogCom::ping() const
{
	std::cout << "KreogCom " << this->m_serial << " currently at " << this->_x << " " << this->_y << std::endl;
}

void	KreogCom::locateSquad() const
{
	if (this->next)
		this->next->locateSquad();	
	this->ping();
}