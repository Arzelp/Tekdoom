/*
** gen.c for gen in /home/alies/rendu/gfx_tekdoom
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan 13 14:43:11 2016 Arnaud Alies
** Last update Thu Jan 21 19:27:14 2016 alies_a
*/

#include <lapin.h>
#include <stdlib.h>
#include "map.h"

t_map	*map_gen(int size)
{
  t_map	*res;
  int	x;
  int	max;

  max = (size * size * size);
  if ((res = bunny_malloc(sizeof(t_map))) == NULL)
    return (NULL);
  (res->head).version = MAP_VERSION;
  (res->head).size = size;
  (res->head).offset = 0;
  x = 0;
  if ((res->blocks = bunny_malloc(sizeof(t_block) * max)) == NULL)
    return (NULL);
  while (x < max)
    {
      ((res->blocks)[x]).x = 0;
      ((res->blocks)[x]).texture = 0;
      x += 1;
    }
  return (res);
}

void		map_set_flat(t_map *map)
{
  t_block	block;
  t_pos		pos;
  int		size;

  block.x = 1;
  block.texture = 3;
  size = (map->head).size;
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  while (pos.y < size)
    {
      map_set(map, &pos, block);
      pos.x += 1;
      if (pos.x > size)
	{
	  pos.x = 0;
	  pos.y += 1;
	}
    }
}

void            map_set_wall(t_map *map)
{
  t_block	block;
  t_pos		pos;
  int		size;

  block.x = 1;
  block.texture = 1;
  size = (map->head).size;
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  while (pos.z < size)
    {
      if (pos.x + 2 > size ||
	  pos.y + 2 > size ||
	  pos.z + 2 > size ||
	  pos.x == 0 ||
	  pos.y == 0 ||
	  pos.z < 10)
	map_set(map, &pos, block);
      pos.x += 1;
      if (pos.x > size)
	{
	  pos.x = 0;
	  pos.y += 1;
	}
      if (pos.y > size)
	{
	  pos.y = 0;
	  pos.z += 1;
	}
    }
}
