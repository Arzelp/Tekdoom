/*
** map_delete_block.c for map delete in /src/map/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Jan 17 21:37:39 2016 Frederic ODDOU
** Last update Sun Jan 17 21:37:39 2016 Frederic ODDOU
*/

#include <stdlib.h>
#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "doom_base.h"
#include "map.h"

void		map_delete_block(t_data *data)
{
  t_pos		pos;
  t_block	*block;

  pos.x = (data->me.pos).x + cos((data->me).alpha) * 2;
  pos.y = (data->me.pos).y + sin((data->me).alpha) * 2;
  pos.z = (data->me.pos).z + sin((data->me).beta) * 2;
  if ((block = map_get(data->map, &pos)) != NULL)
    {
      if (block->x >= 1)
	block->x = 0;
    }
}
