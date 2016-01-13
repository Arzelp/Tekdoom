/*
** map_check_pos.c for map trans get in /src/map/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Jan 13 18:19:15 2016 Frederic ODDOU
** Last update Wed Jan 13 18:19:15 2016 Frederic ODDOU
*/

#include <stdlib.h>
#include "map.h"

int		map_check_pos(t_map *map, int x, int y)
{
  t_pos		pos;
  t_block	*block;

  pos.x = x;
  pos.y = y;
  if ((block = map_get(map, &pos)) != NULL)
    return (block->x);
  return (0);
}
