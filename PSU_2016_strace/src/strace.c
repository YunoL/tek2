/*
** strace.c for strace in /home/guillaume2.roux/rendu/PSU_2016_strace/src/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Apr 11 15:54:26 2017 guillaume2.roux
** Last update Fri Apr 14 15:47:30 2017 guillaume2.roux
*/

#include "../include/my.h"

void	flag_s()
{}

void	execute(char **av, char **env, char *path)
{
  if (execve(path, &av[2], env) == -1)
    my_puterr("Error : execve !\n");
}

void	flag_p(char **av, char **env)
{
	pid_t	child_pid;
  char	*path;

  path = get_path(av[1]);
  if (path)
    {
      child_pid = fork();
      if (child_pid == -1)
	my_puterr("Error : fork !\n");
      else if (!child_pid)
	execute(av, env, path);
      free(path);
    }
  else
    my_puterr("Error : no such file !\n");
}
