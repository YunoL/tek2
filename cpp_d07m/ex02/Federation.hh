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

#include "Destination.hh"
#include "WarpSystem.hh"
#include <iostream>

namespace Federation
{
	namespace Starfleet
	{
		class Captain
		{
		public:
			Captain(std::string name);
			~Captain(void);
			std::string	getName(void);
			int	getAge(void);
			void	setAge(int age);
		private:
			std::string	_name;
			int	_age;
		};
		
		class Ship
		{
		public:
			Ship(int length, int width, std::string name, short maxWarp);
			~Ship(void);
			void	setupCore(WarpSystem::Core*	core);
			void	checkCore(void);
			void	promote(Captain *captain);
			bool move(int warp, Destination d);
			bool move(int warp);
			bool move(Destination d);
			bool move();
		private:
			int	_length;
			int	_width;
			std::string	_name;
			short	_maxWarp;
			WarpSystem::Core*	_core;
			Captain	*_captain;
			Destination	_location;
			Destination	_home;
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