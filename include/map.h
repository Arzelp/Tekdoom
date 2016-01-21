/*
** map.h for map in /home/alies/rendu/gfx_tekdoom
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Wed Jan 13 13:36:19 2016 Arnaud Alies
** Last update Thu Jan 21 18:57:23 2016 alies_a
*/

#ifndef MAP_H_
#define MAP_H_

#define MAP_VERSION (1)

#include <stdint.h>

/*
** map file format:
** <header>
** <textures> textures starts just after header
** <blocks> blocks start after offset defined in the header
*/

typedef struct s_pos
{
  int x;
  int y;
  int z;
} t_pos;

typedef struct s_block
{
  uint32_t x;
  uint32_t texture;
} __attribute__((packed)) t_block;

typedef struct s_map_head
{
  uint32_t      version;
  int           size;
  uint32_t      offset;
} __attribute__((packed)) t_map_head;

typedef struct s_map
{
  t_map_head head;
  t_block *blocks;
} __attribute__((packed)) t_map;

int	map_print(t_map *map);
t_map   *map_gen(int size);
t_block *map_get(t_map *map, t_pos *pos);
int     map_set(t_map *map, t_pos *pos, t_block block);
void	map_set_flat(t_map *map);
void	map_set_wall(t_map *map);
void	blow_at(t_map *map, t_pos *pos, int size);

int     map_save(t_map *data, const char *name);
t_map   *load_map(const char *name);

#endif
