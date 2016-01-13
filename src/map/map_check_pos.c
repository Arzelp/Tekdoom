/*
** map_check_pos.c for map trans get in /src/map/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Jan 13 18:19:15 2016 Frederic ODDOU
** Last update Wed Jan 13 18:29:23 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "doom.h"
#include "map.h"

int		map_check_pos(t_map *map, t_vec *vec)
{
  t_pos		pos;
  t_block	*block;

  pos.x = vec->x;
  pos.y = vec->y;
  pos.z = vec->z;
  if ((block = map_get(map, &pos)) != NULL)
    return (block->x);
  return (0);
}
