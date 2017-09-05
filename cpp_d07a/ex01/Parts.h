/*
** Parts.h for parts in /home/guillaume2.roux/rendu/cpp_d07a/ex01
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Tue Jan 10 17:44:17 2017 Guillaume Roux
** Last update Tue Jan 10 17:44:18 2017 Guillaume Roux
*/

#ifndef PARTS_H_
#define PARTS_H_

#include <iostream>

class Arms
{
public:
	Arms(std::string serial = "A-01", bool functionnal = true);
	~Arms();
	bool	isFunctionnal();
	std::string	serial();
	void	informations();
private:
	std::string	_serial;
	bool	_functionnal;
};

class Legs
{
public:
	Legs(std::string serial = "L-01", bool functionnal = true);
	~Legs();
	bool	isFunctionnal();
	std::string	serial();
	void	informations();
private:
	std::string	_serial;
	bool	_functionnal;
};

class Head
{
public:
	Head(std::string serial = "H-01", bool functionnal = true);
	~Head();
	bool	isFunctionnal();
	std::string	serial();
	void	informations();
private:
	std::string	_serial;
	bool	_functionnal;
};

#endif