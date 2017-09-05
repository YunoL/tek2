/*
** main.c for main in /home/guillaume2.roux/rendu/PSU_2016_lemipc/src/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Sun Apr  2 14:06:55 2017 guillaume2.roux
** Last update Sun Apr  2 14:23:45 2017 guillaume2.roux
*/

#include <stdio.h>
#include <stdlib.h>

void	lemipc(char *path_key, int player_num)
{
  (void)path_key;
  (void)player_num;
}

int	main(int ac, char **av)
{
  if (ac == 3)
    lemipc(av[1], atoi(av[2]));
  else
    {
      fprintf(stderr, "USAGE:\t%s path_to_key team_number\n\n\tpath_to_key is a valid path that will be used by ftok\n", av[0]);
      fprintf(stderr, "\tteam_number is the team number assigned to the current player\n");
    }
  return (0);
}
