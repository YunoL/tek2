//
// koaladoctor.cpp for koaladoctor in /home/guillaume2.roux/rendu/cpp_d06/ex04
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Mon Jan  9 15:59:31 2017 Guillaume Roux
// Last update Mon Jan  9 15:59:32 2017 Guillaume Roux
//

#include <fstream>
#include <stdlib.h>
#include "koalanurse.h"
#include "koaladoctor.h"
#include "sickkoala.h"

KoalaDoctor::KoalaDoctor(std::string name)
{
	this->name = name;
	this->work = false;
	std::cout << "Dr. " << name << ": Je suis le Dr." << name << "! Comment Kreoggez-vous ?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{

}

void KoalaDoctor::diagnose(SickKoala* koala)
{
	std::cout << "Dr. " << name << ": Alors, qu'est-ce qui vous goerk, Mr." << koala->getName() << " ?" << std::endl;
	koala->poke();

	int	i = rand() % 5 + 1;
	std::string		filename = koala->getName() + ".report";
	std::ofstream	o(filename.c_str());
	if (i == 1)
		o << "mars";
	else if (i == 2)
		o << "Buronzand";
	else if (i == 3)
		o << "Viagra";
	else if (i == 4)
		o << "Extasy";
	else if (i == 5)
		o << "Feuille d'Eucalyptus";
}

void	KoalaDoctor::timeCheck()
{
	if (this->work)
		std::cout << "Dr." << this->name << ": Je rentre dans ma foret d'eucalyptus!" << std::endl;
	else
		std::cout << "Dr." << this->name << ": Je commence le travail!" << std::endl;
	this->work = !this->work;
}