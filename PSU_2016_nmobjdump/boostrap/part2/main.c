/*
** main.c for main in /home/guillaume2.roux/rendu/PSU_2016_nmobjdump/boostrap/part2/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Wed Feb 15 14:52:55 2017 guillaume2.roux
** Last update Wed Feb 15 15:30:17 2017 guillaume2.roux
*/

#include <fcntl.h>
#include <stdio.h>
#include <elf.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(int ac, char **av)
{
  int fd;
  void *buff;
  struct stat s;
  Elf64_Ehdr *elf;

  fd = open(av[1], O_RDONLY);
  if (fd != -1)
    {
      fstat(fd, &s);
      buff = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
      if (buff != -1)
	{
	  printf("mmap(%s) : %08x\n", av[1], buff);
	  elf = buff;
	  printf("Section Header Table : addr = %08x, nb = %d\n", elf->e_shoff, elf->e_shnum);
	}
      else
	{
	  perror("mmap");
	}
      close(fd);
    }
}
