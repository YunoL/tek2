/*
** Exo-1.h for exo-1 in /home/guillaume2.roux/rendu/cpp_d09/ex-1
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan 12 09:24:29 2017 Guillaume Roux
** Last update Thu Jan 12 09:24:30 2017 Guillaume Roux
*/

#ifndef EXO_1_H_
#define EXO_1_H_

#include <stdio.h>
#include <string.h>

typedef struct s_cthulhu
{
	int	m_power;
	char	*m_name;
}	t_cthulhu;

typedef struct s_koala
{
	t_cthulhu m_parent;
	char	m_isALegend;
}	t_koala;

t_cthulhu*	NewCthulhu();
void	PrintPower(t_cthulhu *this);
void	PrintPower(t_cthulhu *this);
void	Attack(t_cthulhu *this);
void	Sleeping(t_cthulhu *this);
t_koala*	NewKoala(char *name, char _isALegend);
void	Eat(t_koala *this);

#endif