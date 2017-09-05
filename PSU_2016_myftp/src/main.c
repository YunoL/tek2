/*
** main.c for main in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri May 12 13:00:54 2017 Guillaume Roux
** Last update Fri May 19 11:52:32 2017 Guillaume Roux
*/

#include "../include/my.h"

char *home_dir;
bool	user_value;
bool	pass_value;

void	server_run(int fd)
{
  pid_t	pid;
  struct sockaddr_in	s_in;
  int	sock;
  int	client_fd;
  socklen_t	s_in_size;

  while (1)
    {
      s_in_size = sizeof(s_in);
      if ((client_fd = accept(fd, (struct sockaddr *)&s_in, &s_in_size)) == -1)
	closing("Error : can't accept client", fd, EXIT_FAILURE);
      if ((pid = fork()) < 0)
	closing("Error : can't fork", fd, EXIT_FAILURE);
      else if (pid == 0)
	{
	  close(fd);
	  my_write(client_fd, Msg220);
	  manage_client(client_fd);
	  exit(EXIT_SUCCESS);
  }
      close(client_fd);
    }
}

int	main(int ac, char **av)
{
  int	fd;
  struct sockaddr_in	s_in;

  if (ac != 3)
    my_exit(USAGE, EXIT_FAILURE);
  home_dir = av[2];
  check_dir();
  fd = create_socket();
  user_value = false;
  pass_value = false;
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(atoi(av[1]));
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    closing("Error : bind, can't assign address to server", fd, EXIT_FAILURE);
  if (listen(fd, 42) == -1)
    closing("Error : listen, can't create queue", fd, EXIT_FAILURE);
  server_run(fd);
  return (0);
}
