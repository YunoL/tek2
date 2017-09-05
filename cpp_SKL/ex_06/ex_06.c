/*
** ex_06.c for  in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jan  8 02:15:36 2017 David Zeng
** Last update Sun Jan  8 02:15:36 2017 David Zeng
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "list.h"
#include "int.h"
#include "new.h"

void	print_int(Object *value)
{
  printf("%s\n", str(value));
}

int main()
{
    Object* list = new(List, Int);

    pushfront(list, 6);
    pushback(list, 2);
    pushfront(list, 3);
    pushfront(list, 1);

    // assert pushes
    assert(strcmp("1", str(getitem(list, 0))) == 0);
    assert(strcmp("3", str(getitem(list, 1))) == 0);
    assert(strcmp("6", str(getitem(list, 2))) == 0);
    assert(strcmp("2", str(getitem(list, 3))) == 0);

    // assert len
    printf("list size: %zu\n\n", len(list));
    assert(len(list) == 4);

    // assert getitem
    setitem(list, 2, 13);
    assert(strcmp("13", str(getitem(list, 2))) == 0);

    // print values with iterator
    Object* it = begin(list);
    Object* it_end = end(list);
    printf("Iterator : list values\n");
    while (lt(it, it_end))
    {
        printf("%s\n", str(getval(it)));
        incr(it);
    }

    // print values with foreach
    printf("Foreach : list values\n");
    foreach(list, &print_int);

    // assert front and back values
    assert(strcmp("1", str(front(list))) == 0);
    assert(strcmp("2", str(back(list))) == 0);

    delete(it);
    delete(it_end);
    delete(list);
    return 0;
}
