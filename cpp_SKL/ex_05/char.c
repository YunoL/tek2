/*
** char.c for char.c in /home/andrea_j/rendu/PoolCpp/cpp_SKL/ex_04
**
** Made by Julien Andreani
** Login   <andrea_j@epitech.net>
**
** Started on  Sat Jan  7 15:37:40 2017 Julien Andreani
** Last update Sat Jan  7 22:37:07 2017 Meï
*/

#include <stdio.h>
#include <string.h>
#include "char.h"
#include "raise.h"
#include "new.h"

typedef struct		CharClass
{
  Class			base;
  char			x;
  char			*str;
}			CharClass;

static void		Char_ctor(Object* self, va_list *ap)
{
  CharClass		*this = self;

  this->x = va_arg(*ap, int);
  this->str = NULL;
}

static void Char_dtor(Object* self)
{
  CharClass		*this = self;

  if (this->str != NULL)
    free(this->str);
}

static char const	*Char_str(Object *self)
{
  CharClass		*this = self;
  int			len;

  len = snprintf(NULL, 0, "%c", this->x);
  if (this->str != NULL)
    {
      free(this->str);
      this->str = NULL;
    }
  if (!(this->str = malloc(sizeof(char) * (len + 1))))
    raise("Out of memory");
  if (snprintf(this->str, len + 1, "%c", this->x) < 0)
    raise("Out of memory");
  return (this->str);
}

static Object		*Char_add(const Object *self, const Object *other)
{
  const CharClass		*this = self;
  const CharClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Char") != 0)
    raise("Objects of different types");
  return (new(Char, this->x + oth->x));
}

static Object		*Char_sub(const Object *self, const Object *other)
{
  const CharClass		*this = self;
  const CharClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Char") != 0)
    raise("Objects of different types");
  return (new(Char, this->x - oth->x));
}

static Object		*Char_mul(const Object *self, const Object *other)
{
  const CharClass		*this = self;
  const CharClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Char") != 0)
    raise("Objects of different types");
  return (new(Char, this->x * oth->x));
}

static Object		*Char_div(const Object *self, const Object *other)
{
  const CharClass		*this = self;
  const CharClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Char") != 0)
    raise("Objects of different types");
  if (oth->x == 0)
    raise("Charing point exception");
  return (new(Char, this->x / oth->x));
}

static bool		Char_eq(const Object *self, const Object *other)
{
  const CharClass		*this = self;
  const CharClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Char") != 0)
    raise("Objects of different types");
  return (this->x == oth->x);
}

static bool		Char_gt(const Object *self, const Object *other)
{
  const CharClass		*this = self;
  const CharClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Char") != 0)
    raise("Objects of different types");
  return (this->x > oth->x);
}

static bool		Char_lt(const Object *self, const Object *other)
{
  const CharClass		*this = self;
  const CharClass		*oth = other;

  if (!self || !other)
    raise("Don't use a null Object, you moron !");
  if (strcmp(this->base.__name__, oth->base.__name__) != 0 ||
      strcmp(this->base.__name__, "Char") != 0)
    raise("Objects of different types");
  return (this->x < oth->x);
}

static CharClass _description = {
  {
    sizeof(CharClass),
    "Char",
    &Char_ctor,
    &Char_dtor,
    &Char_str,
    &Char_add,
    &Char_sub,
    &Char_mul,
    &Char_div,
    &Char_eq,
    &Char_gt,
    &Char_lt
  },
  0,
  NULL /* str */
};

Class* Char = (Class*) &_description;
