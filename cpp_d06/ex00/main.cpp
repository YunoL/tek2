//
// main.cpp for main in /home/guillaume2.roux/rendu/cpp_d06/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Mon Jan  9 09:06:18 2017 Guillaume Roux
// Last update Mon Jan  9 09:08:39 2017 Guillaume Roux
//

#include <iostream>
#include <stdlib.h>
#include <fstream>

void	checkArg(char *str)
{
	std::ifstream	fs;
	char 			buffer;

	fs.open(str, std::fstream::in);
	if (fs)
	{
		while (!fs.eof())
		{
			buffer = (char) fs.get();
			if (buffer != -1)
				std::cout << buffer;
		}
	}
	else
		std::cerr << "my_cat: " << str << " : No such file or directory" << std::endl;
	fs.close();
}

int	main(int ac, char **av)
{
	int	i = 1;

  if (ac < 2)
  {
    std::cout << "my_cat: Usage: " << av[0] << " file [...]" << std::endl;
    return (1);
  }
  while (av[i])
  {
  	checkArg(av[i]);
  	i++;
  }
  return (0);
}
