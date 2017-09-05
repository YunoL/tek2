/*
** circular_buff.c for circular_buff in /home/guillaume2.roux/rendu/PSU_2016_myirc/utility/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun  6 14:02:39 2017 Guillaume Roux
** Last update Thu Jun  8 16:54:08 2017 Guillaume Roux
*/

#include "../include/utility.h"

int	circ_buff_push(t_circ_buff *c, uint8_t data)
{
  int	next;

  next = c->head + 1;
  if (next >= c->max_len)
    next = 0;
  if (next == c->tail)
    return (-1);
  c->buffer[c->head] = data;
  c->head = next;
  return (0);
}

int	circ_buff_pop(t_circ_buff *c, uint8_t *data)
{
  int	next;

  if (c->head == c->tail)
    return (-1);
  next = c->tail + 1;
  if (next >= c->max_len)
    next = 0;
  *data = c->buffer[c->tail];
  c->tail = next;
  return (0);
}
