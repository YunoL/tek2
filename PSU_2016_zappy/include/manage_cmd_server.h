/*
** manage_cmd_server.h for PSU_2016_zappy in /home/turba_d/projets/PSU_2016_zappy/server_src
**
** Made by dorian turba
** Login   <turba_d@epitech.net>
**
** Started on  Fri Jun 23 13:58:42 2017 dorian turba
** Last update Wed Jun 28 13:21:27 2017 Guillaume Roux
*/

#ifndef MANAGE_CMD_SERVER_H
# define MANAGE_CMD_SERVER_H

# define TOTAL_CMD 12

typedef struct	s_cmd_param
{
  char		*broadcast_msg;
  char		*object_name;
}		t_cmd_param;

typedef struct	s_cmdptr
{
  char		*name;
  void		(*fct_p)(t_cmd_param *cmd, t_data_server *data_server, int fd);
}		t_cmdptr;

void	init_tab(t_cmdptr *cmd_tab);
void	manage_cmd_server(char *buffer, t_data_server *data_server, int fd);

#endif /* !MANAGE_CMD_SERVER_H */
