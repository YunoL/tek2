/*
** main.c for main in /home/guillaume2.roux/rendu/cpp_d01/ex01
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Wed Jan  4 08:56:56 2017 Guillaume Roux
** Last update Wed Jan  4 09:22:54 2017 Guillaume Roux
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	menger(int size, int level, int x, int y);

int   my_pow(int power, int nb)
{
  int result;
  int i;

  i = 0;
  result = 1;
  while (i < power)
  {
    result *= nb;
    i++;
  }
  return (result);
}

void	my_puterr(char *str)
{
  write (2, str, strlen(str));
  exit (84);
}

int	my_getnbr(char *str)
{
  int	nb;

  nb = 0;
  while (*str != '\0')
    {
      nb = (nb * 10) + (*str - 48);
      str++;
    }
  return (nb);
}

int	check_args(char *str)
{
  while (*str != '\0')
    {
      if (*str < 48 || *str > 57)
	return (1);
      str++;
    }
  return (0);
}

int check_pow(int size)
{
  int cmp;
  int power;

  cmp = 3;
  power = 1;
  while (my_pow(power, cmp) < size)
    power++;
  if (my_pow(power, cmp) == size)
    return (0);
  return (1);
}

int	main(int ac, char **av)
{
  int	size;
  int	level;
  
  if (ac != 3 || check_args(av[1]) == 1 || check_args(av[2]) == 1)
    my_puterr("Error: bad type of argument\n");
  size = my_getnbr(av[1]);
  level = my_getnbr(av[2]);
  if (level == 0 || size % 3 == 1 || size < my_pow(level, 3) || check_pow(size) == 1)
    my_puterr("Error: bad numbers\n");
  else
    menger(size, level, 0, 0);
  return (0);
}
