/*
** main.c for main in /home/guillaume2.roux/rendu/PSU_2016_nmobjdump/boostrap/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Wed Feb 15 14:13:00 2017 guillaume2.roux
** Last update Wed Feb 15 14:24:39 2017 guillaume2.roux
*/

#include <unistd.h>
#include <string.h>

int salut = 6;

void toto()
{
  write(1, "mabite\n", 7);
}

int main()
{
  toto();
  return (0);
}
