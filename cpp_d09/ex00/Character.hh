//
// Character.hh for character in /home/guillaume2.roux/rendu/cpp_d09/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Thu Jan 12 10:20:19 2017 Guillaume Roux
// Last update Thu Jan 12 10:20:19 2017 Guillaume Roux
//

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>

class Character
{
public:
	Character(const std::string &, int);
	~Character();
	const std::string &getName() const;
	int getLvl() const;
	int getPv() const;
	int getPower() const;
	int	CloseAttack();
	int RangeAttack();
	void	Heal();
	void	RestorePower();
	void	TakeDamage(int _damage);
	enum AttackRange 
	{ 
		CLOSE, 
		RANGE 
	};
	AttackRange Range;
private:
	std::string	_name;
	int	_level;
	int	_pv;
	int	_power;
	int	_strenght;
	int	_stamina;
	int	_intelligence;
	int _spirit;
	int _agility;
};

#endif