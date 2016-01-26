/*
** map_create_block.c for map create block in /src/map/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Jan 15 15:16:04 2016 Frederic ODDOU
** Last update Tue Jan 26 17:53:00 2016 alies_a
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
  int		i;

  i = 2;
  x.x = 1;
  x.texture = (data->select).selected;
  while (i <= 7)
    {
      pos.x = (data->me.pos).x + cos((data->me).alpha) * i;
      pos.y = (data->me.pos).y + sin((data->me).alpha) * i;
      pos.z = (data->me.pos).z + sin((data->me).beta) * 3;
      if ((block = map_get(data->map, &pos)) != NULL && block->x == 1)
	{
	  pos.x = (data->me.pos).x + cos((data->me).alpha) * (i - 1);
	  pos.y = (data->me.pos).y + sin((data->me).alpha) * (i - 1);
	  if ((block = map_get(data->map, &pos)) != NULL && block->x == 0)
	    map_set(data->map, &pos, x);
	  return ;
	}
      i++;
    }
}
