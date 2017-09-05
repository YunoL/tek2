//
// WarpSystem.hh for warpsystem in /home/guillaume2.roux/rendu/cpp_d07m/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Tue Jan 10 12:08:38 2017 Guillaume Roux
// Last update Tue Jan 10 12:08:41 2017 Guillaume Roux
//

#ifndef WARPSYSTEM_H_
#define WARPSYSTEM_H_

namespace WarpSystem
{
	class QuantumReactor
	{
	public:
		QuantumReactor(void);
		~QuantumReactor(void);
		bool	isStable(void);
		void	setStability(bool value);
	private:
		bool	_stability;
	};

	class Core
	{
	public:
		Core(QuantumReactor	*coreReactor);
		~Core(void);
		QuantumReactor	*checkReactor();
	private:
		QuantumReactor	*_coreReactor;
	};
};

#endif