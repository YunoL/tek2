/*
** Skat.h for Skat in /home/guillaume2.roux/rendu/cpp_d07a/ex00
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Tue Jan 10 16:12:33 2017 Guillaume Roux
** Last update Tue Jan 10 16:12:34 2017 Guillaume Roux
*/

#ifndef SKAT_H_
#define SKAT_H_

#include <string>
#include <iostream>

class Skat
{
public:
	Skat(std::string const& name = "bob", int stimPacks = 15);
	~Skat();
	int&	stimPaks();
	const std::string&	name();
	void	shareStimPaks(int number, int&	stock);
	void	addStimPaks(unsigned int number);
	void	useStimPaks();
	void	status() const;
private:
	int&	_stimPaks;
	std::string	const&	_name;
};

#endif