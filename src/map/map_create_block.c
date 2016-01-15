/*
** map_create_block.c for map create block in /src/map/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Jan 15 15:16:04 2016 Frederic ODDOU
** Last update Fri Jan 15 15:16:04 2016 Frederic ODDOU
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "doom_base.h"
#include "map.h"

void		map_create_block(t_map *map, t_vec vec)
{
  t_pos		pos;
  t_block	x;

  x.x = 1;
  pos.x = vec.x - 1;
  pos.y = vec.y - 1;
  pos.z = vec.z - 1;
  map_set(map, &pos, x);
}
