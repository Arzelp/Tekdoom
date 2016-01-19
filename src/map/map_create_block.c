/*
** map_create_block.c for map create block in /src/map/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Jan 15 15:16:04 2016 Frederic ODDOU
** Last update Mon Jan 18 18:49:40 2016 Arthur Josso
*/

#include <stdlib.h>
#include <lapin.h>
#include <math.h>
#include "doom.h"

void		map_create_block(t_data *data)
{
  t_pos		pos;
  t_block	x;
  t_block	*block;

  x.x = 1;
  x.texture = 4;
  pos.x = (data->me.pos).x + cos((data->me).alpha) * 2;
  pos.y = (data->me.pos).y + sin((data->me).alpha) * 2;
  pos.z = (data->me.pos).z + sin((data->me).beta) * 2;
  if ((block = map_get(data->map, &pos)) != NULL)
    {
      if (block->x == 0)
	map_set(data->map, &pos, x);
      else
	block->texture = (block->texture + 1) % 96;
    }
}
