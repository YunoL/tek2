/*
** pyramid.c for pyramid in /home/guillaume2.roux/rendu/cpp_d01/ex05
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Wed Jan  4 15:12:27 2017 Guillaume Roux
** Last update Wed Jan  4 15:12:29 2017 Guillaume Roux
*/

#include <stdio.h>

int do_rec(int size, int **map, int row, int col)
{
	int	left;
	int	right;

    if (size == row)
        return (0);
    left = map[row][col] + do_rec(size, map, row + 1, col);
    right = map[row][col] + do_rec(size, map, row + 1, col + 1);
    if (left < right)
        return (left);
    return (right);
}

int pyramid_path(int size, int** map)
{
    return (do_rec(size, map, 0, 0));
}
