//
// sickkoala.cpp for sickkoala in /home/guillaume2.roux/rendu/cpp_d06/ex02
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Mon Jan  9 13:19:38 2017 Guillaume Roux
// Last update Mon Jan  9 13:20:35 2017 Guillaume Roux
//

#include "sickkoala.h"

SickKoala::SickKoala(std::string name)
{
	this->name = name;
}

SickKoala::~SickKoala()
{
	std::cout << "Mr. " << this->name << ": Kreooogg!! Je suis gueriiii!" << std::endl;
}

void	SickKoala::poke()
{
  std::cout << "Mr. " << this->name << ": Gooeeeeerrk!! :'(" << std::endl;
}

bool	SickKoala::takeDrug(std::string smth)
{
	if (smth.length() == 4 && (smth[0] | 0X20) == 'm' && (smth[1] | 0X20) == 'a' && (smth[2] | 0X20) == 'r' && (smth[3] | 0X20) == 's')
	{
		std::cout << "Mr. " << this->name << ": Mars, et ca kreog!" << std::endl;
		return (true);
	}
	else if (smth == "Buronzand")
	{
		std::cout << "Mr. " << this->name << ": Et la fatigue a fait son temps!" << std::endl;
		return (true);
	}
	else
	{
		std::cout << "Mr. " << this->name << ": Goerkreog!" << std::endl;
		return (false);
	}
}

void	SickKoala::overDrive(std::string str)
{
	std::string rep = "1337!";
	int	d;
	std::string	w = "Kreog!";

	while ((d = str.find(w, 0)) != -1)
		str.replace(d, 6, rep);
	std::cout << "Mr. " << this->name << ": " << str << std::endl;
}

std::string	SickKoala::getName()
{
	return (this->name);
}