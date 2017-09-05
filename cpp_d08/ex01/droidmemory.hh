//
// droidmemory.hh for droidmemory in /home/guillaume2.roux/rendu/cpp_d08/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Wed Jan 11 12:42:10 2017 Guillaume Roux
// Last update Wed Jan 11 12:42:10 2017 Guillaume Roux
//

#ifndef DROIDMEMORY_H_
#define DROIDMEMORY_H_

#include <iostream>

class DroidMemory
{
public:
	DroidMemory();
	~DroidMemory();
	size_t	getFingerPrint() const;
	size_t	getExp() const;
	void		setFingerPrint(size_t);
	void		setExp(size_t);
	DroidMemory& operator	=(DroidMemory const & droid);
	DroidMemory& operator <<(DroidMemory const &right);
	DroidMemory const& operator >>(DroidMemory &right) const;
	DroidMemory& operator +=(DroidMemory const &right);
	DroidMemory& operator +=(size_t exp);
	DroidMemory& operator +(DroidMemory const &right) const;
	DroidMemory& operator +(size_t exp) const;
private:
	size_t	FingerPrint;
	size_t	Exp;
};

std::ostream & operator<<(std::ostream & os, DroidMemory const & droid);

#endif