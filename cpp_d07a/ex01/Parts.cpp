//
// Parts.cpp for parts in /home/guillaume2.roux/rendu/cpp_d07a/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Tue Jan 10 17:44:12 2017 Guillaume Roux
// Last update Tue Jan 10 17:44:13 2017 Guillaume Roux
//

#include <iostream>
#include "Parts.h"

Arms::Arms(std::string serial, bool functionnal)
{
	this->_serial = serial;
	this->_functionnal = functionnal;
}

Arms::~Arms()
{

}

bool	Arms::isFunctionnal()
{
	return (this->_functionnal);
}

std::string	Arms::serial()
{
	return (this->_serial);
}

void	Arms::informations()
{
	std::string	tmp = "KO";
	if (this->_functionnal == true)
		tmp = "OK";
	std::cout << "\t[Parts] Arms " << this->_serial << " status : " << tmp << std::endl;
}

Legs::Legs(std::string serial, bool functionnal)
{
	this->_serial = serial;
	this->_functionnal = functionnal;
}

Legs::~Legs()
{

}

bool	Legs::isFunctionnal()
{
	return (this->_functionnal);
}

std::string	Legs::serial()
{
	return (this->_serial);
}

void	Legs::informations()
{
	std::string	tmp = "KO";
	if (this->_functionnal == true)
		tmp = "OK";
	std::cout << "\t[Parts] Legs " << this->_serial << " status : " << tmp << std::endl;
}

Head::Head(std::string serial, bool functionnal)
{
	this->_serial = serial;
	this->_functionnal = functionnal;
}

Head::~Head()
{

}

bool	Head::isFunctionnal()
{
	return (this->_functionnal);
}

std::string	Head::serial()
{
	return (this->_serial);
}

void	Head::informations()
{
	std::string	tmp = "KO";
	if (this->_functionnal == true)
		tmp = "OK";
	std::cout << "\t[Parts] Head " << this->_serial << " status : " << tmp << std::endl;
}