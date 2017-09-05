/*
** sickkoalalist.h for sickkoalalist in /home/guillaume2.roux/rendu/cpp_d06/ex05
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Mon Jan  9 17:46:54 2017 Guillaume Roux
** Last update Mon Jan  9 17:46:59 2017 Guillaume Roux
*/

#ifndef SICKKOALALIST_H_
# define SICKKOALALIST_H_

#include <iostream>
#include "sickkoala.h"

class SickKoalaList
{
public:
	SickKoalaList(SickKoala *koala);
	~SickKoalaList();
	bool	isEnd();
	void	append(SickKoalaList* list);
	SickKoala*	getFromName(std::string name);
	SickKoalaList*	remove(SickKoalaList* list);
	SickKoalaList*	removeFromName(std::string name);
	void	dump();
	SickKoala*	getContent();
	SickKoala*	getNext();

private:
	SickKoala*	koala;
	SickKoalaList*	next;
};

#endif /* !SICKKOALALIST_H_ */