/*
** my_objdump.h for my_objdump in /home/guillaume2.roux/rendu/PSU_2016_nmobjdump/include/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Feb 14 14:06:08 2017 guillaume2.roux
** Last update Mon Feb 20 11:54:39 2017 Guillaume Roux
*/

#ifndef MY_OBJDUMP_H_
# define MY_OBJDUMP_H_

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <elf.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <sys/mman.h>
# include <ctype.h>

# define ERR_FIND "Error : No such file !\n"
# define ERR_OPEN "Error : Can't open this file !\n"
# define WARN_FILE "Warning : This is not an ordinary file !\n"
# define FORMAT_ERR "Error : File format not recognized !\n"
# define ERR_MUNMAP "Error : munmap\n"

void	objdump32(void *buffer, char *file);
void	objdump64(void *buffer, char *file);
void	aff_ascii(unsigned int j, unsigned int *z, unsigned char *w, char *t);

#endif
