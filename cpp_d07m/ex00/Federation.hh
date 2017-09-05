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

#include "WarpSystem.hh"
#include <iostream>

namespace Federation
{
	namespace Starfleet
	{
		class Ship
		{
		public:
			Ship(int length, int width, std::string name, short maxWarp);
			~Ship(void);
			void	setupCore(WarpSystem::Core*	core);
			void	checkCore(void);
		private:
			int	_length;
			int	_width;
			std::string	_name;
			short	_maxWarp;
			WarpSystem::Core*	_core;
		};
	};

	class Ship
	{
	public:
		Ship(int length, int width, std::string name);
		~Ship(void);
		void	setupCore(WarpSystem::Core*	core);
		void	checkCore(void);
	private:
		int	_length;
		int	_width;
		std::string	_name;
		short	_maxWarp;
		WarpSystem::Core*	_core;
	};
};

#endif