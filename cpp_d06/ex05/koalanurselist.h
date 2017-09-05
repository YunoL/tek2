/*
** koalanurselist.h for koalanurselist in /home/guillaume2.roux/rendu/cpp_d06/ex05
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Mon Jan  9 17:38:24 2017 Guillaume Roux
** Last update Mon Jan  9 17:38:25 2017 Guillaume Roux
*/

#ifndef KOALANURSELIST_H_
# define KOALANURSELIST_H_

#include <iostream>
#include "sickkoala.h"
#include "koalanurse.h"

class KoalaNurseList
{
public:
	KoalaNurseList(KoalaNurse* nurse);
	~KoalaNurseList();
	bool	isEnd();
	void	append(KoalaNurseList *list);
	KoalaNurse*	getFromID(int id);
	KoalaNurseList*	remove(KoalaNurseList *list);
	KoalaNurseList*	removeFromID(int id);
	void	dump();

private:
	KoalaNurseList*	next;
	KoalaNurse* 		nurse;
};

#endif /* !KOALANURSELIST_H_ */