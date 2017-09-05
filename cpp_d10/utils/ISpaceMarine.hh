//
// ISpaceMarine.hh for ispacemarine in /home/guillaume2.roux/rendu/cpp_d10/ex02
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 13:15:29 2017 Guillaume Roux
// Last update Fri Jan 13 13:15:30 2017 Guillaume Roux
//

#ifndef ISPACEMARINE_H_
#define ISPACEMARINE_H_

class ISpaceMarine
{
public:
	virtual ~ISpaceMarine() {};
	virtual	ISpaceMarine* clone() const = 0;
	virtual	void	battleCry() const = 0;
	virtual	void	rangedAttack() const = 0;
	virtual	void	meleeAttack() const = 0;
};

#endif