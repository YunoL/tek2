/*
** Exo-1.c for exo-1 in /home/guillaume2.roux/rendu/cpp_d09/ex-1
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan 12 09:24:36 2017 Guillaume Roux
** Last update Thu Jan 12 09:24:38 2017 Guillaume Roux
*/

#include <stdlib.h>
#include "Exo-1.h"

static void	CthulhuInitializer(t_cthulhu *this);
static void	KoalaInitializer(t_koala *this, char* _name, char _isALegend);

t_cthulhu*	NewCthulhu()
{
	t_cthulhu	*new;

	new = malloc(sizeof(t_cthulhu));
	CthulhuInitializer(new);
	return (new);
}

void	PrintPower(t_cthulhu *this)
{
	printf("Power => %d\n", this->m_power);
}

void	Attack(t_cthulhu *this)
{
	if (this->m_power >= 42)
	{
		this->m_power -= 42;
		printf("%s attacks and destroys the city\n", this->m_name);
	}
	else
		printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void	Sleeping(t_cthulhu *this)
{
	this->m_power += 42000;
	printf("%s sleeps\n", this->m_name);
}

t_koala*	NewKoala(char *name, char _isALegend)
{
	t_koala	*new;

	new = malloc(sizeof(t_koala));
	KoalaInitializer(new, name, _isALegend);
	return (new);
}

void	Eat(t_koala *this)
{
	this->m_parent.m_power += 42;
	printf("%s eats\n", this->m_parent.m_name);
}

static void	CthulhuInitializer(t_cthulhu *this)
{
	printf("----\n");
	this->m_name = malloc(strlen("Cthulhu"));
	strcpy(this->m_name, "Cthulhu");
	this->m_power = 42;
	printf("Building %s\n", this->m_name);
}

static void	KoalaInitializer(t_koala *this, char* _name, char _isALegend)
{
	CthulhuInitializer(&this->m_parent);
	this->m_parent.m_name = _name;
	if (_isALegend)
		this->m_parent.m_power = 42;
	else
		this->m_parent.m_power = 0;
	this->m_isALegend = _isALegend;
	printf("Building %s\n", this->m_parent.m_name);
}