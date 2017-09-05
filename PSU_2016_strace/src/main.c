/*
** main.c for main in /home/guillaume2.roux/rendu/PSU_2016_strace/src/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Apr  6 17:34:02 2017 guillaume2.roux
** Last update Fri Apr 14 15:40:41 2017 guillaume2.roux
*/

#include "../include/my.h"

void	my_strcat(char *dest, char *src)
{
  if (dest && src)
    strcat(dest, src);
}

char*	pathcat(char *s1, char *s2)
{
  char	*str;

  str = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 2));
  if (str)
    {
      memset(str, 0, strlen(s1) + strlen(s2) + 2);
      my_strcat(str, s1);
      strcat(str, "/");
      my_strcat(str, s2);
    }
  return (str);
}

char	*get_path(char *path)
{
  int	i;
  char	*tmp;
  char	**tab;

  if (path[0] == '.' || path[0] == '/')
    return (strdup(path));
  else if ((tab = my_strd_to_wordtab(getenv("PATH"), ":")))
    {
      for (i = 0; tab[i]; i++)
	{
	  tmp = pathcat(tab[i], path);
    if (tmp && access(tmp, X_OK) != -1)
	    {
	      free_tab(&tab);
	      return (tmp);
	    }
	  free(tmp);
	}
      free_tab(&tab);
    }
  return ((char*)0);
}

int	main(int ac, char **av, char **env)
{
  if (ac == 3 && strcmp(av[1], "-p") == 0)
    flag_p(av, env);
  else
    fprintf(stderr, "%s\n", USAGE);
  return (0);
}
