/*
** map.h for map in /home/alies/rendu/gfx_tekdoom
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan 13 13:36:19 2016 Arnaud Alies
** Last update Wed Jan 13 14:05:01 2016 Arnaud Alies
*/

#ifndef MAP_H_
#define MAP_H_

#include <stdint.h>

typedef struct s_block
{
  uint32_t x;
} __attribute__((packed)) t_block;

typedef s_map_head
{
  uint32_t version;
  uint32_t width;
  uint32_t depth;
  uint32_t height;
  uint32_t offset;
} __attribute__((packed)) t_map_head;

/*
** map file format:
** <header>
** <textures> textures starts just after header
** <blocks> blocks start after offset defined in the header
*/

typedef s_map
{
  t_map_head head;
  t_block ***blocks;
} __attribute__((packed)) t_map;

#endif
