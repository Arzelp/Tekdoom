/*
** map_create_block.c for map create block in /src/map/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Jan 15 15:16:04 2016 Frederic ODDOU
** Last update Fri Jan 15 15:16:04 2016 Frederic ODDOU
*/

#include <stdlib.h>
#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "doom_base.h"
#include "map.h"

void		map_create_block(t_data *data)
{
  t_pos		pos;
  t_block	x;
  t_block	*block;

  x.x = 1;
  x.texture = 4;
  pos.x = (data->me.pos).x + cos((data->me).alpha);
  pos.y = (data->me.pos).y + sin((data->me).alpha);
  pos.z = (data->me.pos).z - 2;
  if ((block = map_get(data->map, &pos)) != NULL)
    {
      if (block->x == 0)
	map_set(data->map, &pos, x);
      else
	block->texture = (block->texture + 1) % 18;
    }
}
