//
// Borg.hh for borg in /home/guillaume2.roux/rendu/cpp_d07m/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Tue Jan 10 13:33:58 2017 Guillaume Roux
// Last update Tue Jan 10 13:33:59 2017 Guillaume Roux
//

#ifndef BORG_H_
#define BORG_H_

#include "Destination.hh"
#include "WarpSystem.hh"

namespace Borg
{
	class Ship
	{
	public:
		Ship(void);
		~Ship(void);
		void	setupCore(WarpSystem::Core*	core);
		void	checkCore(void);
		bool move(int warp, Destination d);
		bool move(int warp);
		bool move(Destination d);
		bool move();
	private:
		int	_side;
		short	_maxWarp;
		WarpSystem::Core*	_core;
		Destination	_home;
		Destination	_location;
	};
};

#endif