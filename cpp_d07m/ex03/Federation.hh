//
// Federation.hh for Federation in /home/guillaume2.roux/rendu/cpp_d07m/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Tue Jan 10 11:57:48 2017 Guillaume Roux
// Last update Tue Jan 10 11:57:49 2017 Guillaume Roux
//

#ifndef FEDERATION_H_
#define FEDERATION_H_

#include <string>
#include <iostream>

namespace Federation 
{
	namespace Starfleet
	{
		class Ship;
		class Captain;
		class Ensign;
	}
	class Ship;
}

#include "WarpSystem.hh"
#include "Destination.hh"
#include "Borg.hh"

namespace Federation
{
	namespace Starfleet
	{
		class Captain
		{
		public:
			Captain(std::string name);
			~Captain(void);
			std::string	getName();
			int	getAge(void);
			void	setAge(int age);
		private:
			std::string	_name;
			int	_age;
		};
		
		class Ship
		{
		public:
			Ship(int length = 289, int width = 132, std::string name = "Entreprise", short maxWarp = 6, int torpedo = 20);
			~Ship(void);
			void	setupCore(WarpSystem::Core*	core);
			void	checkCore(void);
			void	promote(Captain *captain);
			bool move(int warp, Destination d);
			bool move(int warp);
			bool move(Destination d);
			bool move();
			int	getShield(void);
			void	setShield(int value);
			int	getTorpedo(void);
			void	setTorpedo(int nb);
			void	fire(Borg::Ship* ennemy);
			void	fire(int torpedoes, Borg::Ship*	ennemy);
		private:
			int	_length;
			int	_width;
			std::string	_name;
			short	_maxWarp;
			WarpSystem::Core*	_core;
			Captain	*_captain;
			Destination	_location;
			Destination	_home;
			int	_shield;
			int	_photonTorpedo;
		};

		class Ensign
		{
		public:
			Ensign(std::string name);
			~Ensign(void);
		private:
			std::string	_name;
		};
	};

	class Ship
	{
	public:
		Ship(int length, int width, std::string name);
		~Ship(void);
		void	setupCore(WarpSystem::Core*	core);
		void	checkCore(void);
		bool move(int warp, Destination d);
		bool move(int warp);
		bool move(Destination d);
		bool move();
		WarpSystem::Core *getCore(void);
	private:
		int	_length;
		int	_width;
		std::string	_name;
		short	_maxWarp;
		WarpSystem::Core*	_core;
		Destination	_location;
		Destination	_home;
	};
};

#endif