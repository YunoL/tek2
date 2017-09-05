/*
** vertex.c for vertex in /home/guillaume2.roux/rendu/cpp_SKL/ex_02
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
**
** Started on  Sat Jan  7 12:54:38 2017 Guillaume Roux
** Last update Sat Jan  7 22:22:29 2017 Meï
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raise.h"
#include "vertex.h"

typedef struct
{
  Class base;
  int	x, y, z;
  char	*str;
} VertexClass;

static void Vertex_ctor(Object* self, va_list *ap)
{
  VertexClass 	*tmp;

  tmp = (VertexClass *)self;
  tmp->x = va_arg(*ap, int);
  tmp->y = va_arg(*ap, int);
  tmp->z = va_arg(*ap, int);
  tmp->str = NULL;
}

static void Vertex_dtor(Object* self)
{
  VertexClass	*tmp = (VertexClass *)self;

  if (tmp->str != NULL)
    free(tmp->str);
}

static char const	*Vertex_toString(Object *self)
{
  size_t	len = 0;
  VertexClass	*tmp;

  tmp = (VertexClass *)self;
  len = snprintf(NULL, 0, "<Vertex (%d, %d, %d)>", tmp->x, tmp->y, tmp->z);
  if (tmp->str != NULL)
    {
      free(tmp->str);
      tmp->str = NULL;
    }
  if ((tmp->str = malloc(sizeof(char) * (len + 1))) == NULL)
    raise("Out of memory");
  snprintf(tmp->str, len + 1, "<Vertex (%d, %d, %d)>", tmp->x, tmp->y, tmp->z);
  return (tmp->str);
}

static VertexClass _description = {
    { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_toString },
    0, 0, 0, NULL
};

Class* Vertex = (Class*) &_description;
