//
// koalanurse.cpp for koalanurse in /home/guillaume2.roux/rendu/cpp_d06/ex03
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Mon Jan  9 14:29:25 2017 Guillaume Roux
// Last update Mon Jan  9 14:29:26 2017 Guillaume Roux
//

#include <fstream>
#include "koalanurse.h"
#include "sickkoala.h"

KoalaNurse::KoalaNurse(int id)
{
	this->id = id;
	this->work = false;
}

KoalaNurse::~KoalaNurse()
{
	std::cout << "Nurse " << this->id << ": Enfin un peu de repos!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala* patient)
{
	patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string report)
{
	int	pos = report.find(".report");
	std::ifstream	file;
	std::string	drug;
	std::string	koala = "";
	char 				buffer;

	if (pos)
		file.open(report.c_str(), std::fstream::in);
	if (file)
	{
		while (!file.eof())
		{
			buffer = (char) file.get();
			if (buffer != -1)
				drug += buffer;
		}
	}
	koala = report.substr(0, pos);
	if (!koala.empty() && !drug.empty())
		std::cout << "Nurse " << this->id << ": Kreog! Il faut donner un " << drug << " a Mr." << koala << "!" << std::endl;
	else
		return("");
	if (file)
		file.close();
	return (drug);
}

void	KoalaNurse::timeCheck()
{
	if (this->work)
		std::cout << "Nurse " << this->id << ": Je rentre dans ma foret d'eucalyptus!" << std::endl;
	else
		std::cout << "Nurse " << this->id << ": Je commence le travail!" << std::endl;
	this->work = !this->work;
}

int	KoalaNurse::getID()
{
	return (this->id);
}