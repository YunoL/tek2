/*
** xatoi.c for xatoi in /home/guillaume2.roux/rendu/PSU_2016_myirc/utility/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun  6 14:27:07 2017 Guillaume Roux
** Last update Thu Jun  8 11:51:11 2017 Guillaume Roux
*/

#include "../include/utility.h"

int	xatoi(const char *str)
{
  if (!str)
    return (0);
  return (atoi(str));
}

char	*xstrcat(char *s1, char *s2)
{
  char	*str;

  if (!s1)
    {
      str = strdup(s2);
      return (str);
    }
  else if (!s2)
    return (s1);
  else
    return (strcat(s1, s2));
}
