//
// check_cmd_client.cpp for zappy in /home/lurivar/rendu/PSU_2016_zappy/ai_src/
//
// Made by Luc Normandon
// Login   <luc.normandon@epitech.eu@epitech.eu>
//
// Started on  Sat Jul  1 16:47:11 2017 Luc Normandon
// Last update Sun Jul  2 13:48:28 2017 Luc Normandon
//

#include "../include/client.hpp"

void	add_obj(data_flags *client, char obj)
{
	switch (obj)
	{
		case ('l') :
			client->linemate++;
			client->linemateprio = client->linemateprio - 10;
			break;
		case ('d') :
			client->deraumere++;
			client->deraumereprio = client->deraumereprio - 10;
			break;
		case ('s') :
			client->sibur++;
			client->siburprio = client->siburprio - 10;
			break;
		case ('m') :
			client->mendiane++;
			client->mendianeprio = client->mendianeprio - 10;
			break;
		case ('p') :
			client->phiras++;
			client->phirasprio =- 10;
			break;
		case ('t') :
			client->thystame++;
			client->thystameprio =- 10;
			break;
		case ('f') :
			client->food++;
			client->foodprio = (10 - client->food) * 3;
			break;
	}
}

void	look_prio(data_flags *client)
{
	int			i = 0;
	int			x = 7;

	while (client->to_client[x])
	{
		if (client->to_client[x] == ',')
			i++;
		if (client->to_client[x] == 'p' || client->to_client[x] == 'l' || client->to_client[x] == 'd' || client->to_client[x] == 's' || client->to_client[x] == 'm' || client->to_client[x] == 't' || client->to_client[x] == 'f')
		{
			switch (client->to_client[x])
			{
					if (client->phirasprio > 0)
					case 'p' :
						{
							client->obj_to_take = "phiras";
							client->tile_to_go = i;
							return ;
						}
					break;
				case 'l' :
					if (client->linemateprio > 0)
						{
							client->obj_to_take = "linemate";
							client->tile_to_go = i;
							return ;
						}
					break;
				case 'd' :
					if (client->deraumereprio > 0)
						{
							client->obj_to_take = "deraumere";
							client->tile_to_go = i;
							return ;
						}
					break;
				case 's' :
					if (client->siburprio > 0)
						{
							client->obj_to_take = "sibur";
							client->tile_to_go = i;
							return ;
						}
					break;
				case 'm' :
					if (client->mendianeprio > 0)
						{
							client->obj_to_take = "mendiane";
							client->tile_to_go = i;
							return ;
						}
					break;
				case 't' :
					if (client->thystameprio > 0)
						{
							client->obj_to_take = "thystame";
							client->tile_to_go = i;
							return ;
						}
					break;
				case 'f' :
					if (client->foodprio > 0)
						{
							client->obj_to_take = "food";
							client->tile_to_go = i;
							return ;
						}
					break;
				}
			while (client->to_client[x] <= 'z' && client->to_client[x] >= 'a')
				x++;
		}
		x++;
	}
}

void advance(data_flags *client, int i)
{
	std::string cmd;

	while (i > 0)
	{
		cmd = "Forward";
		client->to_server = const_cast<char*>(cmd.c_str());
		init_fct(&client->fd_read, &client->fd_write, client->fd);
		if (FD_ISSET(client->fd, &client->fd_write))
	  	{
				write_server(client->fd, client);
	  	}
		if (FD_ISSET(client->fd, &client->fd_read))
	  	read_server(client->fd, client);
		if (strcmp(client->to_client, "ok"))
		{
			i--;
			client->to_client = NULL;
		}
	}
	client->to_server = NULL;
	client->tile_to_go = -1;
}

void turn(data_flags *client, int i)
{
	int 				x;
	int					j;
	std::string	dir;

	j = 1;
	x = i - client->tile_to_go;
	if (x == 0)
		return ;
	if (x > 0)
		dir = "Right\r";
	else
		dir = "Left\r";
	if (x < 0)
		x = x * -1;

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
	advance(client, x);
}

void goto_obj(data_flags *client)
{
	if (client->tile_to_go == 0)
		return ;
	else if (client->tile_to_go < 4)
	{
		advance(client, 1);
		turn(client, 3);
	}
	else if (client->tile_to_go < 9)
	{
		advance(client, 2);
		turn(client, 8);
	}
	else if (client->tile_to_go < 16)
	{
		advance(client, 3);
		turn(client, 15);
	}
	else if (client->tile_to_go < 25)
	{
		advance(client, 4);
		turn(client, 24);
	}
	else if (client->tile_to_go < 36)
	{
		advance(client, 5);
		turn(client, 35);
	}
	else if (client->tile_to_go < 49)
	{
		advance(client, 6);
		turn(client, 48);
	}
	else if (client->tile_to_go < 62)
	{
		advance(client, 7);
		turn(client, 61);
	}
	else if (client->tile_to_go < 79)
	{
		advance(client, 8);
		turn(client, 78);
	}
}
