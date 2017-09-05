/*
** koalanurse.h for koalanurse in /home/guillaume2.roux/rendu/cpp_d06/ex03
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Mon Jan  9 14:29:36 2017 Guillaume Roux
** Last update Mon Jan  9 14:29:37 2017 Guillaume Roux
*/

#ifndef KOALANURSE_H_
# define KOALANURSE_H_

#include "sickkoala.h"

class KoalaNurse
{
public:
	KoalaNurse(int id);
	~KoalaNurse();
	void	timeCheck();
	void	giveDrug(std::string drug, SickKoala* patient);
	std::string	readReport(std::string report);
	int	getID();

private:
	int	id;
	bool	work;
};

#endif /* !KOALANURSE_H_ */