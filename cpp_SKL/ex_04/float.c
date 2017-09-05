/*
** float.c for float.c in /home/andrea_j/rendu/PoolCpp/cpp_SKL/ex_04
**
** Made by Julien Andreani
** Login   <andrea_j@epitech.net>
**
** Started on  Sat Jan  7 14:35:18 2017 Julien Andreani
** Last update Sat Jan  7 22:30:14 2017 Meï
*/

#include <stdio.h>
#include <string.h>
#include "float.h"
#include "raise.h"
#include "new.h"

typedef struct		FloatClass
{
  Class			base;
  float			x;
  char			*str;
}			FloatClass;

static void		Float_ctor(Object* self, va_list *ap)
{
  FloatClass		*this = self;

  this->x = va_arg(*ap, double);
  this->str = NULL;
}

static void Float_dtor(Object* self)
{
  FloatClass		*this = self;

  if (this->str != NULL)
    free(this->str);
}

static char const	*Float_str(Object *self)
{
  FloatClass		*this = self;
  int			len;

  len = snprintf(NULL, 0, "%f", this->x);
  if (!(this->str = malloc(sizeof(char) * (len + 1))))
    raise("Out of memory");
  if (snprintf(this->str, len + 1, "%f", this->x) < 0)
    raise("Out of memory");
  return (this->str);
}

static Object		*Float_add(const Object *self, const Object *other)
{
  const FloatClass		*this = self;
  const FloatClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Float") != 0)
    raise("Objects of different types");
  return (new(Float, this->x + oth->x));
}

static Object		*Float_sub(const Object *self, const Object *other)
{
  const FloatClass		*this = self;
  const FloatClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Float") != 0)
    raise("Objects of different types");
  return (new(Float, this->x - oth->x));
}

static Object		*Float_mul(const Object *self, const Object *other)
{
  const FloatClass		*this = self;
  const FloatClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Float") != 0)
    raise("Objects of different types");
  return (new(Float, this->x * oth->x));
}

static Object		*Float_div(const Object *self, const Object *other)
{
  const FloatClass		*this = self;
  const FloatClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Float") != 0)
    raise("Objects of different types");
  if (oth->x == 0)
    raise("Floating point exception");
  return (new(Float, this->x / oth->x));
}

static bool		Float_eq(const Object *self, const Object *other)
{
  const FloatClass		*this = self;
  const FloatClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Float") != 0)
    raise("Objects of different types");
  return (this->x == oth->x);
}

static bool		Float_gt(const Object *self, const Object *other)
{
  const FloatClass		*this = self;
  const FloatClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Float") != 0)
    raise("Objects of different types");
  return (this->x > oth->x);
}

static bool		Float_lt(const Object *self, const Object *other)
{
  const FloatClass		*this = self;
  const FloatClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Float") != 0)
    raise("Objects of different types");
  return (this->x < oth->x);
}

static FloatClass _description = {
  {
    sizeof(FloatClass),
    "Float",
    &Float_ctor,
    &Float_dtor,
    &Float_str,
    &Float_add,
    &Float_sub,
    &Float_mul,
    &Float_div,
    &Float_eq,
    &Float_gt,
    &Float_lt
  },
  0,
  NULL /* str */
};

Class* Float = (Class*) &_description;
