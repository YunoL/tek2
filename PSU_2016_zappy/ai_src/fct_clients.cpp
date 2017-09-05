//
// fct_clients.cpp for  in /home/lurivar/rendu/PSU_2016_zappy/ai_src/
//
// Made by Luc Normandon
// Login   <luc.normandon@epitech.eu@epitech.eu>
//
// Started on  Fri Jun 23 11:43:06 2017 Luc Normandon
// Last update Sun Jul  2 13:38:31 2017 Luc Normandon
//

#include "../include/client.hpp"

void	write_server(int fd, data_flags *d_flags)
{
  if (d_flags->to_server)
    {
	  strcat(d_flags->to_server, "\r");
      dprintf(fd, "%s", d_flags->to_server);
      d_flags->to_server = NULL;
    }
}

void	write_client(data_flags *d_flags)
{
  if (d_flags->to_client)
    {
      std::cout << d_flags->to_client;
      d_flags->to_client = NULL;
    }
}

void	check_ckwa(data_flags *client, char *cmd, char *obj)
{
	char **str = new char *[14];

	if (strcmp(client->to_client, "dead") == 0)
		my_exit("dead", EXIT_SUCCESS);
	if (strcmp(cmd, "Inventory") == 0)
	{
		std::cout << "lol" << std::endl;
		str = my_strd_to_wordtab(client->to_client, (char *)" ,");
		client->food = std::stoi(str[1]);
		client->foodprio = (10 - client->food) * 3;
		std::cout << str << std::endl;
	}
	if (strcmp(cmd, "Take") == 0)
	{
		if (strcmp(client->to_client, "ok") == 0)
			add_obj(client, obj[0]);
	}
	if (strcmp(cmd, "Look") == 0)
	{
		look_prio(client);
	}
  client->to_client = NULL;
}

void	read_server(int fd, data_flags *d_flags)
{
  int	r;
  int	x = 1;
  char	buffer[4096];

  while (x == 1)
  {
	if (FD_ISSET(fd, &d_flags->fd_read))
	{
  		r = read(fd, buffer, 4096);
  		if (r > 0)
   		{
      		buffer[r] = '\0';
      		if (d_flags->to_client)
				d_flags->to_client = NULL;
			d_flags->to_client = strdup(buffer);
    	}
		x = 2;
	}
  }
}
