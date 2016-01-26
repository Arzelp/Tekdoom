/*
** map_delete_block.c for map delete in /src/map/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Jan 17 21:37:39 2016 Frederic ODDOU
** Last update Mon Jan 18 17:48:47 2016 alies_a
*/

#include <stdlib.h>
#include <lapin.h>
#include <math.h>
#include "doom.h"

void			map_delete_block(t_data *data)
{
  t_bunny_position	pos;
  t_hit			hit;
  t_block		*block;

  pos.x = WIDTH / 2;
  pos.y = HEIGHT / 2;
  get_point(data, &pos, &hit);
  set_hit_info(&hit);
  if (map_limite_portee(data, hit) == 0)
    {
      if (!((hit.blk).y == (int)(data->me.pos).y &&
	    (hit.blk).x == (int)(data->me.pos).x) &&
	  (block = map_get(data->map, &(hit.blk))) != NULL && block->x == 1)
	block->x = 0;
    }
}
