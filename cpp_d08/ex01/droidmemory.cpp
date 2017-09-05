//
// droidmemory.cpp for droidmemory in /home/guillaume2.roux/rendu/cpp_d08/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Wed Jan 11 12:42:17 2017 Guillaume Roux
// Last update Wed Jan 11 12:42:18 2017 Guillaume Roux
//

#include <cstdlib>
#include <iostream>
#include "droidmemory.hh"

DroidMemory::DroidMemory() : Exp(0)
{
	this->FingerPrint = random();
}

DroidMemory::~DroidMemory()
{

}

size_t	DroidMemory::getFingerPrint() const
{
	return (this->FingerPrint);
}

size_t	DroidMemory::getExp() const
{
	return (this->Exp);
}

void		DroidMemory::setFingerPrint(size_t fingerprint)
{
	this->FingerPrint = fingerprint;
}

void		DroidMemory::setExp(size_t exp)
{
	this->Exp = exp;
}

DroidMemory& DroidMemory::operator	=(DroidMemory const & droid)
{
	this->FingerPrint = droid.FingerPrint;
	this->Exp = droid.Exp;
	return (*this);
}

DroidMemory& DroidMemory::operator <<(DroidMemory const &right)
{
	this->Exp = this->Exp + right.Exp;
	this->FingerPrint = this->FingerPrint ^ right.FingerPrint;
	return (*this);
}

DroidMemory const& DroidMemory::operator >>(DroidMemory &right) const
{
	right.Exp = this->Exp + right.Exp;
	right.FingerPrint = this->FingerPrint ^ right.FingerPrint;
	return (*this);
}

DroidMemory& DroidMemory::operator +=(DroidMemory const &right)
{
	*this << right;
	return (*this);
}

DroidMemory& DroidMemory::operator +=(size_t exp)
{
	this->Exp = this->Exp + exp;
	this->FingerPrint = this->FingerPrint ^ exp;
	return (*this);
}

DroidMemory& DroidMemory::operator +(DroidMemory const &right) const
{
	DroidMemory 	*memory = new DroidMemory();
	memory->Exp = this->Exp + right.Exp;
	memory->FingerPrint = this->FingerPrint ^ right.FingerPrint;
	return (*memory);
}

DroidMemory& DroidMemory::operator +(size_t exp) const
{
	DroidMemory 	*memory = new DroidMemory();
	memory->Exp = this->Exp + exp;
	memory->setFingerPrint(this->FingerPrint ^ exp);
	return (*memory);
}

std::ostream & operator<<(std::ostream & os, DroidMemory const & droid)
{
	return (os << "DroidMemory '" << droid.getFingerPrint() << "', " << droid.getExp());
}