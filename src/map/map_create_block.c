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

void		map_create_block(t_data *data, t_map *map, t_vec vec)
{
  t_pos		pos;
  t_block	x;

  x.x = 1;
  pos.x = vec.x;
  if (cos((data->me).alpha) >= (sqrt(2) / 2))
    pos.x++;
  else if (cos((data->me).alpha) <= -(sqrt(2) / 2))
    pos.x--;
  pos.y = vec.y;
  if (sin((data->me).alpha) >= (sqrt(2) / 2))
    pos.y++;
  else if (sin((data->me).alpha) >= -(sqrt(2) / 2))
    pos.y--;
  pos.z = vec.z;
  if (sin((data->me).beta) >= (sqrt(2) / 2))
    pos.z++;
  else if (sin((data->me).beta) >= (sqrt(2) / 2))
    pos.z--;
  map_set(map, &pos, x);
}
