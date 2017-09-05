/*
** simple_btree.c for simple_btree in /home/guillaume2.roux/rendu/cpp_d02a/ex01
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan  5 16:05:48 2017 Guillaume Roux
** Last update Thu Jan  5 16:05:53 2017 Guillaume Roux
*/

#include <stdlib.h>
#include "simple_btree.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

t_bool	btree_is_empty(t_tree tree)
{
	if (tree == NULL)
		return (TRUE);
	return (FALSE);
}

unsigned int	btree_get_size(t_tree tree)
{
	unsigned int	i;

	if (tree == NULL)
		return(0);
	i = 1 + btree_get_size(tree->right) + btree_get_size(tree->left);
	return (i);
}

unsigned int	btree_get_depth(t_tree tree)
{
	unsigned int	i_left;
	unsigned int	i_right;

	if (tree == NULL)
		return (0);
	i_left = btree_get_depth(tree->left);
	i_right = btree_get_depth(tree->right);
	if (i_left > i_right)
		return (i_left + 1);
	return (i_right + 1);
}

t_bool	btree_create_node(t_tree *node_ptr, double value)
{
	if ((*node_ptr = malloc(sizeof(t_node))) == NULL)
		return (FALSE);
	(*node_ptr)->value = value;
	return (TRUE);
}

t_bool	btree_delete(t_tree	*root_ptr)
{
	if (*root_ptr == NULL)
		return (FALSE);
	*root_ptr = NULL;
	return (TRUE);
}

double	btree_get_max_value(t_tree	tree)
{
	double			i_left;
	double			i_right;
	double			max;
	double			root;

	if (tree == NULL)
		return (0.0);
	root = tree->value;
	i_left = btree_get_max_value(tree->left);
	i_right = btree_get_max_value(tree->right);
	if (i_left > i_right)
		max = i_left;
	else
		max = i_right;
	if (max < root)
		max = root;
	return (max);
}

double	btree_get_min_value(t_tree tree)
{
	double	i_left;
	double	i_right;

	if (tree == NULL)
		return (0.0);
	i_right = btree_get_min_value(tree->right);
	i_left = btree_get_min_value(tree->left);
	if (tree->left && tree->right)
		return(MIN(MIN(i_right, i_left), tree->value));
	else if (tree->left)
		return (MIN(i_left, tree->value));
	else if (tree->right)
		return (MIN(i_right, tree->value));
	return (tree->value);
}