/*
** main.c for main in /home/guillaume2.roux/rendu/cpp_plazza/src/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Apr 11 16:57:34 2017 guillaume2.roux
** Last update Tue Apr 25 13:12:12 2017 guillaume2.roux
*/

#include "../include/my.hh"
#include "../include/Plazza.hh"

int	main(int ac, char **av)
{
  if (ac != 2)
  {
    std::cerr << "USAGE:\n\t" << av[0] << " nb\n\nDESCRIPTION\n\tnb\tnumber of threads per process" << std::endl;
    return -1;
  }
  Plazza  Place(av[1]);
  return 0;
}
