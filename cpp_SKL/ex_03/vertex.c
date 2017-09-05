/*
** vertex.c for vertex in /home/guillaume2.roux/rendu/cpp_SKL/ex_02
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
**
** Started on  Sat Jan  7 12:54:38 2017 Guillaume Roux
** Last update Sat Jan  7 22:21:58 2017 Meï
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new.h"
#include "raise.h"
#include "vertex.h"

typedef struct
{
  Class	base;
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
  size_t	len;
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

static Object	*Vertex_add(Object const *self, Object const *other)
{
  VertexClass	*a;
  VertexClass	*b;
  Object	*res;

  if (other == NULL)
    raise("Don't use a null Object, you moron !");
  a = (VertexClass *)self;
  b = (VertexClass *)other;

  if (strcmp(a->base.__name__, b->base.__name__) != 0)
    raise("Both objects aren't Vertex. Add aborted");

  res = new(Vertex, (a->x + b->x), (a->y + b->y), (a->z + b->z));
  return (res);
}

static Object	*Vertex_sub(Object const *self, Object const *other)
{
  VertexClass	*a;
  VertexClass	*b;
  Object	*res;

  if (other == NULL)
    raise("Don't use a null Object, you moron !");
  a = (VertexClass *)self;
  b = (VertexClass *)other;

  if (strcmp(a->base.__name__, b->base.__name__) != 0)
    raise("Both objects aren't Vertex. Sub aborted");

  res = new(Vertex, (a->x - b->x), (a->y - b->y), (a->z - b->z));
  return (res);
}

static VertexClass _description = {
  { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_toString, &Vertex_add, &Vertex_sub },
  0, 0, 0, NULL
};

Class* Vertex = (Class*) &_description;
