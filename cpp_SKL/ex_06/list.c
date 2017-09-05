/*
** list.c for list in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sat Jan  7 21:12:42 2017 David Zeng
** Last update Sat Jan  7 21:12:42 2017 David Zeng
*/

#include <stdlib.h>
#include <stdarg.h>

#include "raise.h"
#include "list.h"
#include "new.h"

#include "int.h"

typedef struct	Node
{
  Object	*obj;
  struct Node	*next;
  struct Node	*prev;
}		Node;

typedef struct
{
  Container	base;
  Class		*_type;
  size_t	_size;
  Node		*_front;
  Node		*_back;
}		ListClass;

typedef struct
{
  Iterator	base;
  ListClass	*_list;
  Node		*_node;
  size_t	_idx;
}		ListIteratorClass;

void	ListIterator_ctor(ListIteratorClass *self, va_list *args)
{
  self->_list = va_arg(*args, ListClass *);
  self->_node = va_arg(*args, Node *);
  self->_idx = va_arg(*args, size_t);
}

bool	ListIterator_eq(ListIteratorClass *self, ListIteratorClass *other)
{
  if (self->_list != other->_list)
    return (false);
  return (self->_idx == other->_idx);
}

bool	ListIterator_gt(ListIteratorClass *self, ListIteratorClass *other)
{
  if (self->_list != other->_list)
    return (false);
  return (self->_idx > other->_idx);
}

bool	ListIterator_lt(ListIteratorClass *self, ListIteratorClass *other)
{
  if (self->_list != other->_list)
    return (false);
  return (self->_idx < other->_idx);
}

void	ListIterator_incr(ListIteratorClass *self)
{
  self->_idx += 1;
  if (self->_node == NULL)
    raise("Out of range");
  self->_node = self->_node->next;
}

void	ListIterator_decr(ListIteratorClass *self)
{
  self->_idx -= 1;
  if (self->_node == NULL)
    raise("Out of range");
  self->_node = self->_node->prev;
}

Object	*ListIterator_getval(ListIteratorClass *self)
{
  if (self->_node == NULL)
    raise("Out of range");
  return (self->_node->obj);
}

void	ListIterator_setval(ListIteratorClass *self, ...)
{
  va_list	ap;

  va_start(ap, self);
  if (self->_node == NULL)
    raise("Out of range");

  delete(self->_node->obj);
  self->_node->obj = va_new(self->_list->_type, &ap);
  va_end(ap);
}

static ListIteratorClass ListIteratorDescr = {
  {
    {
      sizeof(ListIteratorClass), "ListIterator",
      (ctor_t) &ListIterator_ctor, NULL,
      NULL,
      NULL, NULL, NULL, NULL,
      (binary_comparator_t) &ListIterator_eq,
      (binary_comparator_t) &ListIterator_gt,
      (binary_comparator_t) &ListIterator_lt,
    },
    (incr_t) &ListIterator_incr,
    (decr_t) &ListIterator_decr,
    (getval_t) &ListIterator_getval,
    (setval_t) NULL,
  },
  NULL,
  NULL,
  0
};

static Class	*ListIterator = (Class *) &ListIteratorDescr;

void	List_ctor(ListClass *self, va_list *args)
{
  self->_type = va_arg(*args, Class *);
  self->_size = 0;
  self->_front = NULL;
  self->_back = NULL;
}

void	List_dtor(ListClass *self)
{
  Node	*node = self->_front;

  while (node != NULL)
    {
      Node *prev = node;
      node = node->next;
      delete(prev->obj);
      free(prev);
    }
}

size_t	List_len(ListClass *self)
{
  return (self->_size);
}

Iterator	*List_begin(ListClass *self)
{
  return (new(ListIterator, self, self->_front, 0));
}

Iterator	*List_end(ListClass *self)
{
  return (new(ListIterator, self, NULL, self->_size));
}

Iterator	*List_beforeend(ListClass *self)
{
  return (new(ListIterator, self, NULL, self->_size - 1));
}

Object	*List_getitem(ListClass *self, ...)
{
  va_list	ap;

  va_start(ap, self);

  size_t	idx = va_arg(ap, size_t);

  if (idx >= self->_size)
    raise("Out of range");

  Node		*node = self->_front;
  for (size_t i = 0; i < idx; i++)
    {
      node = node->next;
    }
  va_end(ap);
  return (node->obj);
}

void	List_setitem(ListClass *self, ...)
{
  va_list	ap;

  va_start(ap, self);

  size_t	idx = va_arg(ap, size_t);

  if (idx >= self->_size)
    raise("Out of range");

  Node		*node = self->_front;
  for (size_t i = 0; i < idx; i++)
    {
      node = node->next;
    }
  delete(node->obj);
  node->obj = va_new(self->_type, &ap);
  va_end(ap);
}

void	List_pushback(ListClass *self, ...)
{
  Node        *node = malloc(sizeof(Node));

  if (node == NULL)
    raise("Out of memory");

  va_list	ap;
  va_start(ap, self);

  node->obj = va_new(self->_type, &ap);
  node->prev = self->_back;
  node->next = NULL;
  if (self->_back != NULL)
    self->_back->next = node;
  else
    self->_front = node;
  self->_back = node;
  self->_size = self->_size + 1;
  va_end(ap);
}

void	List_pushfront(ListClass *self, ...)
{
  Node        *node = malloc(sizeof(Node));

  if (node == NULL)
    raise("Out of memory");

  va_list	ap;
  va_start(ap, self);

  node->obj = va_new(self->_type, &ap);
  node->prev = NULL;
  node->next = self->_front;
  if (self->_front != NULL)
    self->_front->prev = node;
  else
    self->_back = node;
  self->_front = node;
  self->_size = self->_size + 1;
  va_end(ap);
}

void	List_foreach(ListClass *self, ...)
{
  va_list	ap;
  va_start(ap, self);

  void		(*fun)(Object *) = va_arg(ap, void *);

  for (Node *node = self->_front; node != NULL; node = node->next)
    {
      fun(node->obj);
    }

  va_end(ap);
}

bool	List_empty(ListClass *self)
{
  return (self->_size == 0);
}

Object	*List_front(ListClass *self)
{
  if (self->_size == 0)
    raise("List is empty");
  return (self->_front->obj);
}

Object	*List_back(ListClass *self)
{
  if (self->_size == 0)
    raise("List is empty");
  return (self->_back->obj);
}

static ListClass _descr = {
  {
    {
      sizeof(ListClass), "List",
      (ctor_t) &List_ctor, (dtor_t) &List_dtor,
      NULL, /*str */
      NULL, NULL, NULL, NULL, /* add, sub, mul, div */
      NULL, NULL, NULL, /* eq, gt, lt */
    },
    (len_t) &List_len,
    (iter_t) &List_begin,
    (iter_t) &List_end,
    (iter_t) &List_beforeend,
    (getitem_t) &List_getitem,
    (setitem_t) &List_setitem,
    (pushfront_t) &List_pushfront,
    (pushback_t) &List_pushback,
    (foreach_t) &List_foreach,
    (empty_t) &List_empty,
    (front_t) &List_front,
    (back_t) &List_back,
  },
  NULL, 0, NULL, NULL,
};

Class	*List = (Class *) &_descr;
