//
// WarpSystem.cpp for warpsystem in /home/guillaume2.roux/rendu/cpp_d07m/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Tue Jan 10 12:11:26 2017 Guillaume Roux
// Last update Tue Jan 10 12:11:27 2017 Guillaume Roux
//

#include <iostream>
#include "WarpSystem.hh"

WarpSystem::QuantumReactor::QuantumReactor(void)
{
	this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor(void)
{

}

bool	WarpSystem::QuantumReactor::isStable(void)
{
	return (this->_stability);
}

void	WarpSystem::QuantumReactor::setStability(bool value)
{
	this->_stability = value;
}

WarpSystem::Core::Core(QuantumReactor	*coreReactor)
{
	this->_coreReactor = coreReactor;
}

WarpSystem::Core::~Core(void)
{

}

WarpSystem::QuantumReactor*	WarpSystem::Core::checkReactor()
{
	return (this->_coreReactor);
}

