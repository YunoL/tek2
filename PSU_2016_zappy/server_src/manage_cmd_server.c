/*
** manage_cmd_server.c for manage_cmd_server in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Jun 23 13:29:13 2017 Guillaume Roux
** Last update Fri Jun 30 14:13:35 2017 Guillaume Roux
*/

#include "../include/server.h"

void	init_cmd(t_cmd_param *cmd, char **tab)
{
  cmd->broadcast_msg = NULL;
  cmd->object_name = NULL;
  if (tab[1])
    {
      cmd->broadcast_msg = strdup(tab[1]);
      cmd->object_name = strdup(tab[1]);
    }
}

void	init_tab(t_cmdptr *cmd_tab)
{
  (cmd_tab[0].name = strdup("Forward")) && (cmd_tab[0].fct_p = &forward);
  (cmd_tab[1].name = strdup("Right")) && (cmd_tab[1].fct_p = &right);
  (cmd_tab[2].name = strdup("Left")) && (cmd_tab[2].fct_p = &left);
  (cmd_tab[3].name = strdup("Look")) && (cmd_tab[3].fct_p = &look);
  (cmd_tab[4].name = strdup("Inventory")) && (cmd_tab[4].fct_p = &inventory);
  (cmd_tab[5].name = strdup("Broadcast")) && (cmd_tab[5].fct_p = &broadcast);
  (cmd_tab[6].name = strdup("Connect_nbr")) && (cmd_tab[6].fct_p = &connect_nbr);
  (cmd_tab[7].name = strdup("Fork")) && (cmd_tab[7].fct_p = &my_fork);
  (cmd_tab[8].name = strdup("Eject")) && (cmd_tab[8].fct_p = &eject);
  (cmd_tab[9].name = strdup("Take")) && (cmd_tab[9].fct_p = &take);
  (cmd_tab[10].name = strdup("Set")) && (cmd_tab[10].fct_p = &set);
  (cmd_tab[11].name = strdup("Incantation")) && (cmd_tab[11].fct_p = &incantation);
}

void		manage_cmd_server(char *buffer, t_data_server *data_server, int fd)
{
  char		**tab;
  int		i;
  t_cmdptr	cmd_tab[TOTAL_CMD];
  t_cmd_param	cmd;

  i = 0;
  if (buffer[0] == '\0' || buffer[0] == '\n')
    return;
  tab = my_strd_to_wordtab(buffer, " ");
  init_tab(cmd_tab);
  init_cmd(&cmd, tab);
  while (i < TOTAL_CMD)
    {
      if (tab[0] && xstrcmp(tab[0], cmd_tab[i].name) == 0)
	{
	  cmd_tab[i].fct_p(&cmd, data_server, fd);
	  i = TOTAL_CMD;
	}
      i++;
    }
}
