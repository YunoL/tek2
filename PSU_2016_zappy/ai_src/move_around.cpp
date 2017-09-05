//
// NomDeFichier.txt.cpp for zappy in /home/lurivar/rendu/PSU_2016_zappy/ai_src/
//
// Made by Luc Normandon
// Login   <luc.normandon@epitech.eu@epitech.eu>
//
// Started on  Sat Jul  1 20:25:36 2017 Luc Normandon
// Last update Sat Jul  1 20:35:34 2017 Luc Normandon
//

#include "../include/client.hpp"

void go_random(data_flags *client)
{
  std::string dir;
  int         j;

  srand (time(NULL));
  if ((j = rand() % 3) == 0)
    dir = "Right\r";
  else if (j == 1)
    dir = "Left\r";
  else
    dir = "Forward\r";
  j = 1;
  while (j == 1)
    {
      init_fct(&client->fd_read, &client->fd_write, client->fd);
      if (FD_ISSET(client->fd, &client->fd_write))
        {
          dprintf(client->fd, "%s", const_cast<char*>(dir.c_str()));
        }
      if (FD_ISSET(client->fd, &client->fd_read))
        read_server(client->fd, client);
      if (strcmp(client->to_client, "ok"))
      {
        j = 0;
        client->to_client = NULL;
      }
    }
  advance(client, rand() % 10 + 3);
}

void	taken_two(data_flags *client)
{
	int	i;

	i = 1;
	while (i == 1)
	{
		init_fct(&client->fd_read, &client->fd_write, client->fd);
		if (FD_ISSET(client->fd, &client->fd_write))
		{
			dprintf(client->fd, "%s", const_cast<char*>(client->obj_to_take.c_str()));
		}
		if (FD_ISSET(client->fd, &client->fd_read))
			read_server(client->fd, client);
		if (strcmp(client->to_client, "ok"))
		{
			i = 0;
			switch (client->obj_to_take[0])
			{
				case 'l' :
					client->linemate++;
					client->linemateprio -= 10;
					break;
				case 'd' :
					client->deraumere++;
					client->deraumereprio -= 10;
					break;
				case 's' :
					client->sibur++;
					client->siburprio -= 10;
					break;
				case 'p' :
					client->phiras++;
					client->phirasprio -= 10;
					break;
				case 'm' :
					client->mendiane++;
					client->mendianeprio -= 10;
					break;
				case 't' :
					client->thystame++;
					client->thystameprio -= 10;
					break;
				case 'f' :
					client->food++;
					client->foodprio = (10 - client->food) * 3;
					break;
			}
			client->obj_to_take = "";
		}
	}
}
