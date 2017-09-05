/*
** my.h for my in /home/guillaume2.roux/rendu/PSU_2016_strace/include/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Apr  6 17:48:54 2017 guillaume2.roux
** Last update Thu Apr 13 17:22:08 2017 guillaume2.roux
*/

#ifndef MY_H_
# define MY_H_

# define USAGE "Usage : ./strace [-s] [-p <pid> | <command>]"

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/ptrace.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>

void	my_puterr(char *str);
char	*get_path(char *path);
void	flag_p(char **av, char **env);
char	**my_strd_to_wordtab(char *str, char *delim);
void	free_tab(char ***tab);

#endif
