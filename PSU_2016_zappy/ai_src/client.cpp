//
// client.cpp for zappy in /home/lurivar/rendu/PSU_2016_zappy/ai_src/
//
// Made by Luc Normandon
// Login   <luc.normandon@epitech.eu@epitech.eu>
//
// Started on  Thu Jun 22 11:56:11 2017 Luc Normandon
// Last update Sun Jul  2 13:37:41 2017 Luc Normandon
//

#include "../include/client.hpp"

void	init_fct(fd_set *fd_read, fd_set *fd_write, int fd)
{
  FD_ZERO(fd_read);
  FD_ZERO(fd_write);
  FD_SET(1, fd_write);
  FD_SET(fd, fd_read);
  FD_SET(fd, fd_write);
}

bool  start_playing(data_flags *d_flags, int fd)
{
  int x;

  x = 0;
  if (d_flags->to_client)
  {
    if (strcmp(d_flags->to_client, "WELCOME\r\n") == 0)
      {
        d_flags->to_server = strdup(d_flags->name);
        while (x == 0)
        {
          init_fct(&d_flags->fd_read, &d_flags->fd_write, fd);
          if (FD_ISSET(fd, &d_flags->fd_write))
          {
            write_server(fd, d_flags);
            std::cout << "WELCOME" << "\r\n";
            x++;
          }
        }
        return true;
      }
  }
  return false;
}

void client_playing(int fd, data_flags *client)
{
  init_fct(&client->fd_read, &client->fd_write, fd);
  look_around(client);
  send_cmd(client);
  check_answer(client);
}

void	check_isset(fd_set *fd_read, fd_set *fd_write, int fd, data_flags *d_flags)
{
  if (FD_ISSET(1, fd_write))
   write_client(d_flags);
  if (FD_ISSET(fd, fd_write))
   write_server(fd, d_flags);
  if (FD_ISSET(fd, fd_read))
   read_server(fd, d_flags);
}
