//
// arg_check_client.cpp for zappy in /home/lurivar/rendu/PSU_2016_zappy/ai_src/
//
// Made by Luc Normandon
// Login   <luc.normandon@epitech.eu@epitech.eu>
//
// Started on  Mon Jun 19 15:24:45 2017 Luc Normandon
// Last update Tue Jun 27 14:46:51 2017 Luc Normandon
//

#include "../include/arg_check_client.hpp"
#include "../include/err_client.hpp"

int	print_usage()
{
  std::cout << USAGE;
  return 1;
}

int	arg_num_check(int ac)
{
  if (ac == 1 || ac > 7)
    return (error(INV_NBR_ARG));
  else
    return 0;
}

int	arg_flag_check(int ac, char **av, data_flags *d_flags)
{
	for (int i = 0; i < ac; ++i)
		{
      if (av[i] == std::string("-help"))
        return print_usage();
			if (av[i] == std::string("-p") && av[i + 1] != 0)
				d_flags->port = std::stoi(av[i + 1]);
			if (av[i] == std::string("-n") && av[i + 1] != 0)
				d_flags->name = av[i + 1];
			if (av[i] == std::string("-h") && av[i + 1] != 0 && av[i + 1] != std::string("-p") && av[i + 1] != std::string("-n"))
				d_flags->machine = av[i + 1];
			}
	if ((d_flags->port == 0) || (d_flags->name == NULL))
		return 1;
	return 0;
}

int arg_check_client(int ac, char **av, data_flags *d_flags)
{
	if (arg_num_check(ac) == 1)
		return 1;
	if (arg_flag_check(ac, av, d_flags) == 1)
		return 1;
	return 0;
}
