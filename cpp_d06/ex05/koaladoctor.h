/*
** koaladoctor.h for koaladoctor in /home/guillaume2.roux/rendu/cpp_d06/ex04
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Mon Jan  9 15:59:40 2017 Guillaume Roux
** Last update Mon Jan  9 15:59:41 2017 Guillaume Roux
*/

#ifndef KOALADOCTOR_H_
# define KOALADOCTOR_H_

# include <iostream>
# include "sickkoala.h"

class KoalaDoctor
{
public:
	KoalaDoctor(std::string name);
	~KoalaDoctor();
	void diagnose(SickKoala* koala);
	void	timeCheck();
	std::string	getName();

private:
	std::string	name;
	bool	work;
};

#endif /* !KOALADOCTOR_H_ */