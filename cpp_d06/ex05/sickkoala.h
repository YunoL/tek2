/*
** sickkoala.h for sickkoala in /home/guillaume2.roux/rendu/cpp_d06/ex02
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Mon Jan  9 13:11:41 2017 Guillaume Roux
** Last update Mon Jan  9 13:11:42 2017 Guillaume Roux
*/

#ifndef SICK_KOALA_H_
# define SICK_KOALA_H_

# include <iostream>

class SickKoala
{
public:
	SickKoala(std::string name);
	~SickKoala();
	void	poke();
	bool	takeDrug(std::string smth);
	void	overDrive(std::string str);
	std::string	getName();

private:
	std::string	name;
};

#endif /* SICK_KOALA_H_ */