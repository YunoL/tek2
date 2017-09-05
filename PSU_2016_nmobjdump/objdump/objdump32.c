/*
** objdump32.c for objdump32 in /home/guillaume/rendu/PSU_2016_nmobjdump/objdump/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Feb 17 10:13:42 2017 Guillaume Roux
** Last update Fri Feb 24 10:49:19 2017 Guillaume Roux
*/

#include "../include/my_objdump.h"

void	aff_ascii(unsigned int j, unsigned int *z, unsigned char *w, char *t)
{
  int	x;

  x = j;
  while (x % 16 != 0)
    {
      if (x % 4 == 0 && x % 16)
	printf(" ");
      printf("  ");
      x++;
    }
  printf("  ");
  while (*z < j)
    {
      if (isprint(w[*z]))
	printf("%c", t[*z]);
      else
	printf(".");
      (*z)++;
    }
  while ((*z) % 16 != 0)
    {
      printf(" ");
      (*z)++;
    }
  *z = j;
  printf("\n");
}

void	print_part(char *str, Elf32_Ehdr *elf, Elf32_Shdr *shdr, int i)
{
  unsigned char *w;
  unsigned int	j;
  unsigned int	z;
  int						address;

  address = shdr[i].sh_addr;
  printf("Contents of section %s:\n", &str[shdr[i].sh_name]);
  w = (unsigned char *)((char*)elf + shdr[i].sh_offset);
  j = 0;
  z = 0;
  while (j < shdr[i].sh_size)
    {
      if (j % 16 == 0)
	printf(" %04x ", address);
      printf("%02x", w[j++]);
      if (j % 4 == 0 && j % 16 && j < shdr[i].sh_size)
	printf(" ");
      if (j % 16 == 0)
	address += 16;
      if (j % 16 == 0 || j >= shdr[i].sh_size)
	aff_ascii(j, &z, w, (char*)w);
    }
}

void 	print32(char *str, Elf32_Ehdr *elf, Elf32_Shdr *shdr)
{
  int	i;

  i = 0;
  while (i < elf->e_shnum)
    {
      if (shdr[i].sh_size && strcmp(&str[shdr[i].sh_name], ".strtab") &&
	  strcmp(&str[shdr[i].sh_name], ".symtab") &&
	  strcmp(&str[shdr[i].sh_name], ".shstrtab") &&
	  strcmp(&str[shdr[i].sh_name], ".bss"))
	{
	  print_part(str, elf, shdr, i);
	}
      i++;
    }
}

void					objdump32(void *buffer, char *file)
{
  Elf32_Ehdr	*elf;
  Elf32_Shdr	*shdr;
  char				*str;

  elf = (Elf32_Ehdr*)buffer;
  shdr = (Elf32_Shdr*)(buffer + elf->e_shoff);
  str = (char*)(buffer + shdr[elf->e_shstrndx].sh_offset);
  printf("\n%s:%5cfile format\n", file, ' ');
  printf("architecture: %s, flags 0x%08x:\n\n", elf->e_machine == 3 ?
	 "i386" : "notf", elf->e_flags);
  printf("start address 0x%08x\n\n", elf->e_entry);
  print32(str, elf, shdr);
}
