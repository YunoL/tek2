/*
** int.c for int in /home/zeng_d/rendu/PiscineCPP/cpp_SKL/ex_01
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sat Jan  7 14:30:54 2017 David Zeng
** Last update Sat Jan  7 22:28:19 2017 Meï
*/

#include <stdio.h>
#include <string.h>
#include "new.h"
#include "raise.h"
#include "int.h"

typedef struct
{
  Class	base;
  int	value;
  char	*str;
} IntClass;

static bool		Int_eq(const Object *self, const Object *other)
{
  if (other == NULL)
    raise("Don't use a null Object, you moron");

  const IntClass	*this = self;
  const IntClass	*nb = other;

  if (strcmp(this->base.__name__, "Int") != 0 ||
      strcmp(this->base.__name__, nb->base.__name__) != 0)
    raise("Not the same type");

  return (this->value == nb->value);
}

static bool		Int_gt(const Object *self, const Object *other)
{
  if (other == NULL)
    raise("Don't use a null Object, you moron");

  const IntClass	*this = self;
  const IntClass	*nb = other;

  if (strcmp(this->base.__name__, "Int") != 0 ||
      strcmp(this->base.__name__, nb->base.__name__) != 0)
    raise("Not the same type");

  return (this->value > nb->value);
}

static bool		Int_lt(const Object *self, const Object *other)
{
  if (other == NULL)
    raise("Don't use a null Object, you moron");

  const IntClass	*this = self;
  const IntClass	*nb = other;

  if (strcmp(this->base.__name__, "Int") != 0 ||
      strcmp(this->base.__name__, nb->base.__name__) != 0)
    raise("Not the same type");

  return (this->value < nb->value);
}

static Object		*Int_div(const Object *self, const Object *other)
{
  if (other == NULL)
    raise("Don't use a null Object, you moron");

  const IntClass	*this = self;
  const IntClass	*nb = other;

  if (strcmp(this->base.__name__, "Int") != 0 ||
      strcmp(this->base.__name__, nb->base.__name__) != 0)
    raise("Not the same type");

  if (nb->value == 0)
    raise("Floating point exception");

  return (new(Int, this->value / nb->value));
}

static Object		*Int_mul(const Object *self, const Object *other)
{
  if (other == NULL)
    raise("Don't use a null Object, you moron");

  const IntClass	*this = self;
  const IntClass	*nb = other;

  if (strcmp(this->base.__name__, "Int") != 0 ||
      strcmp(this->base.__name__, nb->base.__name__) != 0)
    raise("Not the same type");

  return (new(Int, this->value * nb->value));
}

static Object		*Int_sub(const Object *self, const Object *other)
{
  if (other == NULL)
    raise("Don't use a null Object, you moron");

  const IntClass	*this = self;
  const IntClass	*nb = other;

  if (strcmp(this->base.__name__, "Int") != 0 ||
      strcmp(this->base.__name__, nb->base.__name__) != 0)
    raise("Not the same type");

  return (new(Int, this->value - nb->value));
}

static Object		*Int_add(const Object *self, const Object *other)
{
  if (other == NULL)
    raise("Don't use a null Object, you moron");

  const IntClass	*this = self;
  const IntClass	*nb = other;

  if (strcmp(this->base.__name__, "Int") != 0 ||
      strcmp(this->base.__name__, nb->base.__name__) != 0)
    raise("Not the same type");

  return (new(Int, this->value + nb->value));
}

static char const	*Int_str(Object *self)
{
  IntClass	*this = self;
  int		len = snprintf(NULL, 0, "%d", this->value);

  if (this->str != NULL)
    {
      free(this->str);
      this->str = NULL;
    }

  this->str = malloc(sizeof(char) * (len + 1));

  if (this->str == NULL)
    raise("Out of memory");

  snprintf(this->str, len + 1, "%d", this->value);
  return (this->str);
}

static void Int_ctor(Object* self, va_list *args)
{
  IntClass	*this = self;

  this->value = va_arg(*args, int);
  this->str = NULL;
}

static void Int_dtor(Object* self)
{
  IntClass	*this = self;

  if (this->str != NULL)
    free(this->str);
}

static IntClass _description = {
  { sizeof(IntClass),
    "Int",
    &Int_ctor,
    &Int_dtor,
    &Int_str,
    &Int_add,
    &Int_sub,
    &Int_mul,
    &Int_div,
    &Int_eq,
    &Int_gt,
    &Int_lt
  },
  0,
  NULL /* str */
};

Class* Int = (Class*) &_description;
