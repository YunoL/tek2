/*
** main.c for main in /home/guillaume2.roux/rendu/cpp_d01/ex04
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Wed Jan  4 14:57:01 2017 Guillaume Roux
** Last update Wed Jan  4 14:57:03 2017 Guillaume Roux
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "drawing.h"
#include "bitmap.h"

void    my_puterr(char *str)
{
    write (2, str, strlen(str));
    exit (84);
}

int main(int ac, char** av)
{
    size_t size;
    uint32_t level;
    t_bmp_header header;
    t_bmp_info_header info;
    t_point p = {0, 0};

    if (ac != 4)
        my_puterr("menger_face file_name size level\n");
    size = atoi(av[2]);
    level = atoi(av[3]);
    make_bmp_header(&header, size);
    make_bmp_info_header(&info, size);
    return (0);
}
