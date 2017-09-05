/*
** objdump.c for objdump in /home/guillaume2.roux/rendu/PSU_2016_nmobjdump/src/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Feb 14 11:40:56 2017 guillaume2.roux
** Last update Mon Feb 20 11:59:17 2017 Guillaume Roux
*/

#include "../include/my_objdump.h"

int		check_file(char *file)
{
  int	fd;

  if (access(file, F_OK) == -1)
    {
      write(2, ERR_FIND, strlen(ERR_FIND));
      return (-1);
    }
  else if ((fd = open(file, O_RDONLY, 0)) == -1)
    {
      write(2, ERR_OPEN, strlen(ERR_OPEN));
      return (-1);
    }
  return (fd);
}

void	*check_mmap(int fd, char *file, long size)
{
  void	*buffer;

  if ((buffer = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED)
    {
      close(fd);
      write(2, WARN_FILE, strlen(WARN_FILE));
      return (MAP_FAILED);
    }
  return (buffer);
}

void 					my_objdump(char *file)
{
  void				*buffer;
  Elf32_Ehdr	*elf;
  int 				fd;
  long 				size;

  if ((fd = check_file(file)) == -1)
    return;
  if ((buffer = check_mmap(fd, file, size)) == MAP_FAILED)
    return;
  elf = (Elf32_Ehdr*)buffer;
  if (elf->e_ident[EI_CLASS] == ELFCLASS32)
    objdump32(buffer, file);
  else if (elf->e_ident[EI_CLASS] == ELFCLASS64)
    objdump64(buffer, file);
  if (close(fd) == -1)
    write(2, ERR_MUNMAP, strlen(ERR_MUNMAP));
  if (munmap(buffer, size) == -1)
    write(2, ERR_MUNMAP, strlen(ERR_MUNMAP));
}

int 	main(int ac, char **av)
{
  int	i;

  i = 1;
  if (ac < 1)
    my_objdump("./a.out");
  while (i < ac)
    {
      my_objdump(av[i]);
      i++;
    }
  return (0);
}
