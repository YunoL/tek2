/*
** action_time.h for action_time in /home/guillaume2.roux/rendu/PSU_2016_zappy/include/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Wed Jun 21 13:32:33 2017 Guillaume Roux
** Last update Wed Jun 21 13:40:42 2017 Guillaume Roux
*/

#ifndef ACTION_TIME_H
# define ACTION_TIME_H

// Time Nb/f to execute an action
# define T_MOVE 7
# define T_TURN 7
# define T_LOOK 7
# define T_INVENTORY 1
# define T_BROADCAST 7
# define T_FORK 42
# define T_EJECT 7
# define T_TAKE_OBJ 7
# define T_SET_OBJ 7
# define T_START_INC 300

// Response to action
# define REP_GOOD "ok"
# define REP_BAD "ko"
# define REP_DEATH "dead"
# define REP_INCANTATION "Elevation underway\nCurrent level : "

#endif
