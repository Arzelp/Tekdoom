/*
** tnt.c for tnt in /home/alies_a/rendu/gfx_tekdoom
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan 21 18:48:39 2016 alies_a
** Last update Tue Jan 26 13:49:16 2016 alies_a
*/

#include <math.h>
#include "doom.h"

static void	blow_rad(t_data *data, t_pos *pos, int size)
{
  t_pos		bpos;
  t_block	block;
  float		radx;
  float		rady;

  block.x = 0;
  block.texture = 0;
  rady = 0;
  while (rady < 2 * M_PI)
    {
      radx = 0;
      while (radx < 2 * M_PI)
	{
	  bpos.x = sin(radx) * cos(rady) * size + pos->x;
	  bpos.y = sin(rady) * size + pos->y;
	  bpos.z = cos(radx) * size + pos->z;
	  kill_all_in_zone(data, &bpos);
	  if (bpos.z > 0)
	    map_set((data->map), &bpos, block);
	  radx += 0.1;
	}
      rady += 0.1;
    }
}

void	blow_at(t_data *data, t_pos *pos, int size)
{
  int	x;

  x = 0;
  while (x < size)
    {
      blow_rad(data, pos, x);
      x += 1;
    }
}
