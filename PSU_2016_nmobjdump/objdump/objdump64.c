/*
** objdump64.c for objdup64 in /home/guillaume/rendu/PSU_2016_nmobjdump/objdump/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Feb 17 15:49:16 2017 Guillaume Roux
** Last update Fri Feb 24 14:54:08 2017 Guillaume Roux
*/

#include "../include/my_objdump.h"

void	print_sect(char *str, Elf64_Ehdr *elf, Elf64_Shdr *shdr, int i)
{
  unsigned char		*w;
  unsigned int		j;
  int							addr;
  unsigned int		z;

  addr = shdr[i].sh_addr;
  write(1, "a\n", 2);
  printf("Contents of section %s:\n", &str[shdr[i].sh_name]);
  write(1, "b\n", 2);
  w = (unsigned char*)((char*)elf + shdr[i].sh_offset);
  j = 0;
  z = 0;
  while (j < shdr[i].sh_size)
    {
      if (j % 16 == 0)
	printf(" %04x ", addr);
      printf("%02x", w[j++]);
      if (j % 4 == 0 && j % 16 && j < shdr[i].sh_size)
	printf(" ");
      if (j % 16 == 0)
	addr += 16;
      if (j % 16 == 0 || j >= shdr[i].sh_size)
	aff_ascii(j, &z, w, (char*)w);
    }
}

void 	print64(char *str, Elf64_Ehdr *elf, Elf64_Shdr *shdr)
{
  int	i;

  i = 0;
  while (i < elf->e_shnum)
    {
      if (shdr[i].sh_size && strcmp(&str[shdr[i].sh_name], ".str") &&
	  strcmp(&str[shdr[i].sh_name], ".symtab") &&
	  strcmp(&str[shdr[i].sh_name], ".shstr") &&
	  strcmp(&str[shdr[i].sh_name], ".bss"))
	{
	  print_sect(str, elf, shdr, i);
	}
      i++;
    }
}

void					objdump64(void *buffer, char *file)
{
  Elf64_Ehdr	*elf;
  Elf64_Shdr	*shdr;
  char				*str;

  elf = (Elf64_Ehdr*)buffer;
  shdr = (Elf64_Shdr*)(buffer + elf->e_shoff);
  str = (char*)(buffer + shdr[elf->e_shstrndx].sh_offset);
  printf("\n%s:%5cfile format\n", file, ' ');
  printf("architecture: %s, flags 0x%08x:\n\n", elf->e_machine == 3 ?
	 "i386" : "notf", elf->e_flags);
  printf("start address 0x%016x\n\n", (int)elf->e_entry);
  print64(str, elf, shdr);
}
