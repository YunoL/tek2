//
// droid.cpp for droid in /home/guillaume2.roux/rendu/cpp_d08/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Wed Jan 11 09:17:21 2017 Guillaume Roux
// Last update Wed Jan 11 09:17:22 2017 Guillaume Roux
//

#include <iostream>
#include "droid.hh"
#include "droidmemory.hh"

Droid::Droid(std::string serial) : Id(serial), Energy(50), Attack(25), Toughness(15)
{
	DroidMemory	*tmp = new DroidMemory();
	this->Status = new std::string("Standing by");
	this->BattleData = tmp;
	std::cout << "Droid '" << this->Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &droid) : Id(droid.Id), Energy(50), Attack(25), Toughness(15), BattleData(droid.BattleData)
{
	this->Status = new std::string (*(droid.Status));
	std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
	delete this->Status;
	std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
}

std::string	Droid::getId() const
{
	return (this->Id);
}

size_t	Droid::getEnergy() const
{
	return (this->Energy);
}

size_t	Droid::getAttack() const
{
	return (this->Attack);
}

size_t	Droid::getToughness() const
{
	return (this->Toughness);
}

std::string*	Droid::getStatus() const
{
	return (this->Status);
}

void	Droid::setId(std::string id)
{
	this->Id = id;
}

void	Droid::setEnergy(size_t energy)
{
	if (energy > 100)
		this->Energy = 100;
	else
		this->Energy = energy;
}

void	Droid::setStatus(std::string* status)
{
	if (this->Status)
		delete this->Status;
	this->Status = status;
}

DroidMemory*	Droid::getBattleData()
{
	return (this->BattleData);
}

void	Droid::setBattleData(DroidMemory *data)
{
	delete this->BattleData;
	this->BattleData = data;
}

Droid& Droid::operator	=(Droid const & droid)
{
	this->Id = droid.Id;
	this->Energy = droid.Energy;
	delete this->Status;
	this->Status = new std::string(*(droid.Status));
	return (*this);
}

bool Droid::operator ==(Droid const & droid) const
{
	if (*(this->Status) == *(droid.Status))
		return (true);
	return (false);
}

bool	Droid::operator	!=(Droid const & droid) const
{
	return !(*this == droid);
}

Droid& Droid::operator <<(size_t &energy)
{
	if (this->Energy + energy > 100)
	{
		energy = energy + this->Energy - 100;
		this->Energy = 100;
	}
	else
	{
		this->Energy += energy;
		energy = 0;
	}
	return (*this);
}

bool Droid::operator()(std::string const * task, size_t exp)
{
	if (this->Energy > 10)
	{
		this->Energy -= 10;
		std::string *tmp = new std::string(*task);
		if (*(this->BattleData) >= exp)
		{
			*tmp += " - Completed!";
			setStatus(tmp);
			this->BattleData->setExp(this->BattleData->getExp() + exp / 2);
			return (true);
		}
		else
		{
			*tmp += " - Failed!";
			this->setStatus(tmp);
			this->BattleData->setExp(this->BattleData->getExp() + exp);
			return (false);
		}
	}
	else
	{
		this->Energy = 0;
		this->setStatus(new std::string("Battery Low"));
		return (false);
	}
}

std::ostream & operator<<(std::ostream & os, Droid const & droid)
{
	return (os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy());
}