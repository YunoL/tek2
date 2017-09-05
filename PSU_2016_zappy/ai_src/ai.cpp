//
// ai.cpp for zappy in /home/lurivar/rendu/PSU_2016_zappy/ai_src/
//
// Made by Luc Normandon
// Login   <luc.normandon@epitech.eu@epitech.eu>
//
// Started on  Wed Jun 28 14:51:55 2017 Luc Normandon
// Last update Sun Jul  2 13:44:04 2017 Luc Normandon
//

#include "../include/client.hpp"

void look_around(data_flags *client)
{
  std::string cmd = "Inventory";
  
  client->to_server = const_cast<char*>(cmd.c_str());
  int x = 1;
  while (x == 1)
  {
  init_fct(&client->fd_read, &client->fd_write, client->fd);
	if (FD_ISSET(client->fd, &client->fd_write))
  	{
  		write_server(client->fd, client);
  		x = 2;
  	}
  }
  x = 1;
  while (x == 1)
  {
    init_fct(&client->fd_read, &client->fd_write, client->fd);
    if (FD_ISSET(client->fd, &client->fd_read))
      {
        read_server(client->fd, client);
        x = 2;
      }
  }
  init_fct(&client->fd_read, &client->fd_write, client->fd);
  check_ckwa(client, const_cast<char*>(cmd.c_str()), NULL);
  x = 1;
  cmd = "Look";
  client->to_server = const_cast<char*>(cmd.c_str());
  while (x == 1)
  {
  init_fct(&client->fd_read, &client->fd_write, client->fd);
	if (FD_ISSET(client->fd, &client->fd_write))
  	{
  		write_server(client->fd, client);
  		x = 2;
  	}
  }
  x = 1;
  init_fct(&client->fd_read, &client->fd_write, client->fd);
  while (x == 1)
  {
    init_fct(&client->fd_read, &client->fd_write, client->fd);
    if (FD_ISSET(client->fd, &client->fd_read))
      {
        read_server(client->fd, client);
        x = 2;
      }
  }
  x = 1;
  check_ckwa(client, const_cast<char*>(cmd.c_str()), NULL);
  if (client->tile_to_go != -1)
  {
    goto_obj(client);
    taken_two(client);
  }
  else
    go_random(client);
  //2 : look
  //3 : wait for answer
  //4 : set prio
}

void send_cmd(data_flags *client)
{
  (void)client;
  //3   : si food bas                           > food
  //      sinon si new player                   > fork (pond un oeuf)
  //      sinon si entend une incantation       > go sur place
  //      sinon si peut incanter                > incante
  //      sinon                                 > minerais (a choisir selon dégré d'importance)

}

void check_answer(data_flags *client)
{
  (void)client;
}

void levelup(data_flags *client)
{
  client->level = client->level + 1;
  switch (client->level)
  {
    case 2 :
      client->linemateprio = 10;
      client->deraumereprio = 10;
      client->siburprio = 10;
      break;
    case 3 :
      client->linemateprio = 20;
      client->siburprio = 10;
      client->phirasprio = 20;
      break;
    case 4 :
      client->linemateprio = 10;
      client->deraumereprio = 10;
      client->siburprio = 20;
      client->phirasprio = 10;
      break;
    case 5 :
      client->linemateprio = 10;
      client->deraumereprio = 20;
      client->siburprio = 10;
      client->mendianeprio = 30;
      break;
    case 6 :
      client->linemateprio = 10;
      client->deraumereprio = 20;
      client->siburprio = 30;
      client->phirasprio = 10;
      break;
    case 7 :
      client->linemateprio = 20;
      client->deraumereprio = 20;
      client->siburprio = 20;
      client->mendianeprio = 20;
      client->phirasprio = 20;
      client->thystameprio = 10;
      break;
  }
}
