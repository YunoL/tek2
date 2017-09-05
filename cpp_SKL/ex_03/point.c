/*
** point.c for point in /home/guillaume2.roux/rendu/cpp_SKL/ex_02
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
**
** Started on  Sat Jan  7 12:27:22 2017 Guillaume Roux
** Last update Sat Jan  7 22:22:12 2017 Meï
*/

#include "new.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raise.h"
#include "point.h"

typedef struct
{
  Class base;
  int	x, y;
  char	*str;
} PointClass;

static void Point_ctor(Object* self, va_list *ap)
{
  PointClass 	*tmp;

  tmp = (PointClass *)self;
  tmp->x = va_arg(*ap, int);
  tmp->y = va_arg(*ap, int);
  tmp->str = NULL;
}

static void Point_dtor(Object* self)
{
  PointClass	*tmp;

  tmp = (PointClass *)self;
  if (tmp->str != NULL)
    free(tmp->str);
}


static char const	*Point_toString(Object *self)
{
  size_t	len = 0;
  PointClass	*tmp;

  tmp = (PointClass *)self;
  len = snprintf(NULL, 0, "<Point (%d, %d)>", tmp->x, tmp->y);
  if (tmp->str != NULL)
    {
      free(tmp->str);
      tmp->str = NULL;
    }
  if ((tmp->str = malloc(sizeof(char) * (len + 1))) == NULL)
    raise("Out of memory");
  snprintf(tmp->str, len + 1, "<Point (%d, %d)>", tmp->x, tmp->y);
  return (tmp->str);
}

static Object *Point_add(Object const *p1, Object const *p2)
{
  PointClass  *tmp1;
  PointClass  *tmp2;
  PointClass  *result;

  if (p2 == NULL)
    raise("Don't use a null Object, you moron !");
  tmp1 = (PointClass *)p1;
  tmp2 = (PointClass *)p2;

  if (strcmp(tmp1->base.__name__, tmp2->base.__name__) != 0)
    raise("Both objects aren't Point. Add aborted");

  result = new(Point);
  result->x = tmp1->x + tmp2->x;
  result->y = tmp1->y + tmp2->y;
  return (result);
}

static Object *Point_sub(Object const *p1, Object const *p2)
{
  PointClass  *tmp1;
  PointClass  *tmp2;
  PointClass  *result;

  if (p2 == NULL)
    raise("Don't use a null Object, you moron !");
  tmp1 = (PointClass *)p1;
  tmp2 = (PointClass *)p2;

  if (strcmp(tmp1->base.__name__, tmp2->base.__name__) != 0)
    raise("Both objects aren't Point. Sub aborted");

  result = new(Point);
  result->x = tmp1->x - tmp2->x;
  result->y = tmp1->y - tmp2->y;
  return (result);
}

static PointClass _description = {
    { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_toString, &Point_add, &Point_sub },
    0, 0, NULL
};

Class* Point = (Class*) &_description;
