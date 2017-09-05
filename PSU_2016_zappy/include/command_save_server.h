/*
** command_save_server.h for  in /home/turba_d/projets/PSU_2016_zappy/server_src
**
** Made by dorian turba
** Login   <turba_d@epitech.net>
**
** Started on  Mon Jun 26 14:41:40 2017 dorian turba
** Last update Tue Jun 27 11:50:59 2017 Guillaume Roux
*/

#ifndef COMMAND_SAVE_SERVER_H
# define COMMAND_SAVE_SERVER_H

# include "manage_cmd_server.h"

void	forward(t_cmd_param *cmd, t_data_server *data_server, int fd);
void	right(t_cmd_param *cmd, t_data_server *data_server, int fd);
void	left(t_cmd_param *cmd, t_data_server *data_server, int fd);
void	look(t_cmd_param *cmd, t_data_server *data_server, int fd);
void	inventory(t_cmd_param *cmd, t_data_server *data_server, int fd);
void	broadcast(t_cmd_param *cmd, t_data_server *data_server, int fd);
void	connect_nbr(t_cmd_param *cmd, t_data_server *data_server, int fd);
void	my_fork(t_cmd_param *cmd, t_data_server *data_server, int fd);
void	eject(t_cmd_param *cmd, t_data_server *data_server, int fd);
void	take(t_cmd_param *cmd, t_data_server *data_server, int fd);
void	set(t_cmd_param *cmd, t_data_server *data_server, int fd);
void	incantation(t_cmd_param *cmd, t_data_server *data_server, int fd);

#endif /* !COMMAND_SAVE_SERVER_H */
