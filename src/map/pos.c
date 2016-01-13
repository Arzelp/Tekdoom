/*
** pos.c for pos in /home/alies/rendu/gfx_tekdoom
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan 13 15:58:21 2016 Arnaud Alies
** Last update Wed Jan 13 18:18:10 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "map.h"

static int	in_map(t_map *map, t_pos *pos)
{
  if ((pos->x < size && pos->x >= 0) &&
      (pos->y < size && pos->y >= 0) &&
      (pos->z < size && pos->z >= 0))
    return (1);
  return (0);
}

t_block	*map_get(t_map *map, t_pos *pos)
{
  int	size;
  int	x;

  size = (map->head).size;
  x = pos->x + pos->y * size + pos->z * (size * size);
  if (in_map(map, pos))
    return (&((map->blocks)[x]));
  return (NULL);
}

int	map_set(t_map *map, t_pos *pos, t_block block)
{
  int   size;
  int   x;

  size = (map->head).size;
  x = pos->x + pos->y * size + pos->z * (size * size);
  if (in_map(map, pos))
    {
      ((map->blocks)[x]) = block;
      return (0);
    }
  return (1);
}

