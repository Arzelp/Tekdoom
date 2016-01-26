/*
** map_create_block.c for map create block in /src/map/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Jan 15 15:16:04 2016 Frederic ODDOU
** Last update Wed Jan 20 17:21:59 2016 alies_a
*/

#include <stdlib.h>
#include <lapin.h>
#include <math.h>
#include "doom.h"

void		map_create_block(t_data *data)
{
  t_pos		pos;
  t_block	x;
  t_hit		hit;
  t_block	*block;

  x.x = 1;
  x.texture = (data->select).selected;
  pos.x = WIDTH / 2;
  pos.y = HEIGHT / 2;
  get_point(data, &pos, &hit);
  set_hit_info(&hit);
  if (map_limite_portee(data, hit) == 0)
    {
      if (hit.axe == 'z')
	(hit.blk).z += (sin((data->me).beta) < 0) ? 1 : -1;
      else if (hit.axe == 'y')
	(hit.blk).y += (sin((data->me).alpha) < 0) ? 1 : -1;
      else if (hit.axe == 'x')
	(hit.blk).x += (cos((data->me).alpha) < 0) ? 1 : -1;
      if (!((hit.blk).y == (int)(data->me.pos).y &&
	    (hit.blk).x == (int)(data->me.pos).x) &&
	  (block = map_get(data->map, &(hit.blk))) != NULL && block->x == 0)
	map_set(data->map, &(hit.blk), x);
    }
}
