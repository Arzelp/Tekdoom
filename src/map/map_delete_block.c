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

void		map_delete_block(t_data *data)
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
	    block->x = 0;
	  return ;
	}
      i++;
    }
}
