/*
** mem_ptr.c for mem_ptr in /home/guillaume2.roux/rendu/cpp_d02m/ex01
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan  5 08:21:05 2017 Guillaume Roux
** Last update Thu Jan  5 08:21:06 2017 Guillaume Roux
*/

#include "mem_ptr.h"
#include <stdlib.h>
#include <string.h>

void	add_str(char *str1, char *str2, char **res)
{
	int	len1;
	int	len2;

	len1 = strlen(str1);
	len2 = strlen(str2);
	if (len1 || len2)
	{
		*res = malloc(len1 + len2 + 1);
		strcpy(*res, str1);
		strcat(*res, str2);
	}
	else
		*res = NULL;
}

void	add_str_struct(t_str_op *str_op)
{
	add_str(str_op->str1, str_op->str2, &str_op->res);
}