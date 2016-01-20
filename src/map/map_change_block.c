/*
** map_change_block.c for map change in /src/map/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Jan 20 14:03:13 2016 Frederic ODDOU
** Last update Wed Jan 20 14:03:13 2016 Frederic ODDOU
*/

#include <stdlib.h>
#include <lapin.h>
#include <math.h>
#include "doom.h"

void		map_change_block(t_data *data)
{
  t_pos		pos;
  t_block	*block;
  int		i;

  i = 2;
  while (i <= 7)
    {
      pos.x = (data->me.pos).x + cos((data->me).alpha) * i;
      pos.y = (data->me.pos).y + sin((data->me).alpha) * i;
      pos.z = (data->me.pos).z + sin((data->me).beta) * 3;
      if ((block = map_get(data->map, &pos)) != NULL && block->x == 1)
	{
	  if ((block = map_get(data->map, &pos)) != NULL && block->x == 1)
	    block->texture = (block->texture + 1) % 20;
	  return ;
	}
      i++;
    }
}
