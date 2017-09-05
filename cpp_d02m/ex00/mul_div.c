/*
** mul_div.c for mul_div in /home/guillaume2.roux/rendu/cpp_d02m/ex00
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan  5 08:07:26 2017 Guillaume Roux
** Last update Thu Jan  5 08:07:27 2017 Guillaume Roux
*/

void	add_mul_4param(int first, int second, int *add, int *mul)
{
	*add = first + second;
	*mul = first * second;
}

void	add_mul_2param(int *first, int *second)
{
	*first = *first + *second;
	*second = (*first - *second) * (*second);
}