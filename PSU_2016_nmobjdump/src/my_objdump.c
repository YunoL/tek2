/*
** objdump.c for objdump in /home/guillaume2.roux/rendu/PSU_2016_nmobjdump/src/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Feb 14 11:40:56 2017 guillaume2.roux
** Last update Wed Feb 15 09:44:33 2017 guillaume2.roux
*/

#include "../include/my_objdump.h"

int my_objdump(const char* file)
{
  return (0);
}

int main(int ac, char **av)
{
  int i;

  i = 1;
  while (i < ac)
    {
      printf("\n%s:\n\n", av[i]);
      i++;
    }
  return (0);
}
