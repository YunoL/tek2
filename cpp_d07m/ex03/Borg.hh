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

namespace Borg
{
	class Ship;
}

#include "WarpSystem.hh"
#include "Destination.hh"
#include "Federation.hh"

namespace Borg
{
	class Ship
	{
	public:
		Ship(int weaponFrequency, short repair = 3);
		~Ship(void);
		void	setupCore(WarpSystem::Core*	core);
		void	checkCore(void);
		bool move(int warp, Destination d);
		bool move(int warp);
		bool move(Destination d);
		bool move();
		int	getShield(void);
		void	setShield(int value);
		int	getWeaponFrequency();
		void	setWeaponFrequency(int value);
		short	getRepair();
		void	setRepair(short value);
		void	fire(Federation::Starfleet::Ship*	ennemy);
		void	fire(Federation::Ship*	ennemy);
		void	repair();
	private:
		int	_side;
		short	_maxWarp;
		WarpSystem::Core*	_core;
		Destination	_home;
		Destination	_location;
		int	_shield;
		int	_weaponFrequency;
		short	_repair;
	};
};

#endif