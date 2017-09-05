/*
** my_prog.c for my_prog in /home/guillaume2.roux/rendu/PSU_2016_nmobjdump/boostrap/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Wed Feb 15 14:35:41 2017 guillaume2.roux
** Last update Wed Feb 15 14:47:36 2017 guillaume2.roux
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <gnu/lib-names.h>

#define MY_USAGE "USAGE: ./my_prog <lib.so>\n"
#define MY_ERROR "Error : There is a problem\n"

int main(int ac, char **av)
{
  void* handle;
  char* error;

  if (ac != 2)
    write(2, MY_USAGE, strlen(MY_USAGE));
  else
    {
      handle = dlopen(LIBM_SO, RTLD_LAZY);
      if (!handle)
	{
	  write(2, MY_ERROR, strlen(MY_ERROR));
	  exit(EXIT_FAILURE);
	}
      error = dlerror();
      if (error)
	{
	  write(2, error, strlen(error));
	  exit(EXIT_FAILURE);
	}
      dlclose(handle);
      exit(EXIT_SUCCESS);
    }
  return (0);
}
