/*
** func_ptr.c for func_ptr in /home/guillaume2.roux/rendu/cpp_d02m/ex03
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan  5 09:03:11 2017 Guillaume Roux
** Last update Thu Jan  5 09:03:32 2017 Guillaume Roux
*/

#include <string.h>
#include <stdio.h>
#include "func_ptr.h"
#include "func_ptr_enum.h"

void	print_normal(char *str)
{
	printf("%s\n", str);
}

void	print_reverse(char *str)
{
	int	i;

	i = strlen(str) - 1;
	while (i >= 0)
	{
		printf("%c", str[i]);
		i--;
	}
	printf("\n");
}

void	print_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			printf("%c", str[i] - 32);
		else
			printf("%c", str[i]);
		i++;
	}
	printf("\n");
}

void	print_42(char *str)
{
	(void)str;
	printf("42\n");
}

void	do_action(t_action action, char *str)
{
	void (*ptr[])(char*) = {print_normal, print_reverse, print_upper, print_42};

	(ptr)[action](str);
}