//
// arg_check_client.hpp for zappy in /home/lurivar/rendu/PSU_2016_zappy/include/
//
// Made by Luc Normandon
// Login   <luc.normandon@epitech.eu@epitech.eu>
//
// Started on  Mon Jun 19 15:31:08 2017 Luc Normandon
// Last update Tue Jun 20 13:57:47 2017 Luc Normandon
//

#ifndef ARG_CHECK_CLIENT_HPP
# define ARG_CHECK_CLIENT_HPP

# define USAGE "USAGE: ./zappy_ai -p port -n name -h machine\n\tport\tis the port number\n\tname\tis the name of the team\n\tmachine\tis the name of the machine; localhost by default\n"

#include "client.hpp"

int	print_usage();
int arg_check_client(int ac, char **av, data_flags *d_flags);
int	arg_num_check(int ac);
int	arg_flag_check(int ac, char **av, data_flags *d_flags);

#endif /* !ARG_CHECK_CLIENT_HPP */
