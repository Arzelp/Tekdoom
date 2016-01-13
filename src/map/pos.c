/*
** pos.c for pos in /home/alies/rendu/gfx_tekdoom
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan 13 15:58:21 2016 Arnaud Alies
** Last update Wed Jan 13 18:06:09 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "map.h"

t_block	*map_get(t_map *map, t_pos *pos)
{
  int	size;
  int	x;

  size = (map->head).size;
  x = pos->x + pos->y * size + pos->z * (size * size);
  if (x >= 0 && x < (size * size * size))
    return (&((map->blocks)[x]));
  return (NULL);
}

int	map_set(t_map *map, t_pos *pos, t_block block)
{
  int   size;
  int   x;

  size = (map->head).size;
  x = pos->x + pos->y * size + pos->z * (size * size);
  if (x >= 0 && x < (size * size * size))
    {
      ((map->blocks)[x]) = block;
      return (0);
    }
  return (1);
}

