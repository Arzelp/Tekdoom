/*
** map.h for map in /home/alies/rendu/gfx_tekdoom
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Wed Jan 13 13:36:19 2016 Arnaud Alies
** Last update Wed Jan 13 18:29:55 2016 Arnaud Alies
*/

#ifndef MAP_H_
#define MAP_H_

#define MAP_VERSION (1)

#include <stdint.h>

typedef struct s_block
{
  uint32_t x;
} __attribute__((packed)) t_block;

typedef struct s_map_head
{
  uint32_t version;
  uint32_t size;
  uint32_t offset;
} __attribute__((packed)) t_map_head;

/*
** map file format:
** <header>
** <textures> textures starts just after header
** <blocks> blocks start after offset defined in the header
*/

typedef struct s_map
{
  t_map_head head;
  t_block *blocks;
} __attribute__((packed)) t_map;

typedef struct s_pos
{
  int x;
  int y;
  int z;
} t_pos;

int	map_print(t_map *map);
t_map   *map_gen(int size);
t_block *map_get(t_map *map, t_pos *pos);
int     map_set(t_map *map, t_pos *pos, t_block block);
int	map_check_pos(t_map *map, int x, int y);

#endif
