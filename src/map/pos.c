/*
** pos.c for pos in /home/alies/rendu/gfx_tekdoom
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan 13 15:58:21 2016 Arnaud Alies
** Last update Wed Jan 13 16:09:45 2016 Arnaud Alies
*/

#include "map.h"

t_block	*get_map(t_map *map, int x, int y, int z)
{
  int	size;
  int	pos;

  size = (map->head).size;
  pos = x + y * size + z * (size * size);
  if (pos >= 0 && pos < (size * size * size))
    return (&((map->blocks)[pos]));
  return (NULL);
}

