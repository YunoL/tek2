/*
** koaladoctorlist.h for koaladoctorlist in /home/guillaume2.roux/rendu/cpp_d06/ex05
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Mon Jan  9 17:47:28 2017 Guillaume Roux
** Last update Mon Jan  9 17:47:29 2017 Guillaume Roux
*/

#ifndef KOALADOCTORLIST_H_
# define KOALADOCTORLIST_H_

#include <iostream>
#include "sickkoala.h"
#include "koalanurse.h"
#include "koaladoctor.h"

class KoalaDoctorList
{
public:
	KoalaDoctorList(KoalaDoctor* name);
	~KoalaDoctorList();
	bool	isEnd();
	void	append(KoalaDoctorList *list);
	KoalaDoctor*	getFromName(std::string name);
	KoalaDoctorList*	remove(KoalaDoctorList *list);
	KoalaDoctorList*	removeFromName(std::string name);
	void	dump();

private:
	KoalaDoctorList*	next;
	KoalaDoctor* 		name;
};

#endif /* !KOALADOCTORLIST_H_ */