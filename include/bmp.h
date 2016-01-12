/*
** bmp.h for bmp in /home/alies/rendu/gfx_tekdoom
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan 12 17:06:20 2016 Arnaud Alies
** Last update Tue Jan 12 17:06:21 2016 Arnaud Alies
*/

#ifndef BMP_H_
#define BMP_H_

#include <lapin.h>
#include <stdint.h>

typedef struct s_head{
  uint16_t type;
  uint32_t size;
  uint16_t reserved1;
  uint16_t reserved2;
  uint32_t offset;
} __attribute__((packed)) t_head;

typedef struct s_info{
  uint32_t size;
  int32_t width;
  int32_t height;
  uint16_t planes;
  uint16_t bits;
  uint32_t compression;
  uint32_t imagesize;
  int32_t xresolution;
  int32_t yresolution;
  uint32_t ncolours;
  uint32_t importantcolours;
} __attribute__((packed)) t_info;

t_bunny_pixelarray *load_bitmap(const char *file);

#endif
