//
// droid.hh for droid in /home/guillaume2.roux/rendu/cpp_d08/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Wed Jan 11 09:17:14 2017 Guillaume Roux
// Last update Wed Jan 11 09:17:15 2017 Guillaume Roux
//

#ifndef DROID_H_
#define DROID_H_

#include <iostream>
#include <string>
#include "droidmemory.hh"

class Droid
{
public:
	Droid(std::string serial);
	Droid(Droid const &droid);
	~Droid();
	DroidMemory*	getBattleData();
	void	setBattleData(DroidMemory *data);
	std::string getId() const;
	size_t getEnergy() const;
	size_t getAttack() const;
	size_t getToughness() const;
	std::string *getStatus() const;
	void	setId(std::string id);
	void	setEnergy(size_t energy);
	void	setStatus(std::string *status);
	Droid&	operator=(Droid const & droid);
	bool		operator==(Droid const & droid) const;
	bool		operator !=(Droid const & droid) const;
	Droid&	operator<<(size_t &energy);
	bool 		operator()(std::string const * task, size_t exp);
private:
	std::string	Id;
	size_t	Energy;
	size_t const	Attack;
	size_t const	Toughness;
	std::string	*Status;
	DroidMemory*	BattleData;
};

std::ostream & operator<<(std::ostream & os, Droid const & droid);

#endif