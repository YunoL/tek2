/*
** bitmap_header.c for bitmap_header in /home/guillaume2.roux/rendu/cpp_d01/ex02
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Wed Jan  4 12:40:17 2017 Guillaume Roux
** Last update Wed Jan  4 12:40:19 2017 Guillaume Roux
*/

#include <string.h>
#include "bitmap.h"

int		is_bigendian()
{
    int		nb;
    char	*c;

    nb = 0x70AB12CD;
    c = (char*)&nb;
    if (*c == 0x70)
        return (1);
    return (0);
}

void	make_bmp_header(t_bmp_header* header, size_t size)
{
    memset(header, 0, sizeof(t_bmp_header));
    header->magic = 0x4D42;
    if (is_bigendian() == 1)
        header->magic = 0x424D;
    header->size = size * size * sizeof(uint32_t) + sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
    header->offset = sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
}

void	make_bmp_info_header(t_bmp_info_header* header, size_t size)
{
    memset(header, 0, sizeof(t_bmp_info_header));
    header->size = 40;
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->row_data_size = size * size * sizeof(uint32_t);
    header->v_resolution = 0;
    header->h_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}
