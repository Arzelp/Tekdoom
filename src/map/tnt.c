/*
** tnt.c for tnt in /home/alies_a/rendu/gfx_tekdoom
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan 21 18:48:39 2016 alies_a
** Last update Fri Jan 22 11:02:05 2016 alies_a
*/

#include <math.h>
#include "doom.h"

static void	blow_rad(t_map *map, t_pos *pos, int size)
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
	  map_set(map, &bpos, block);
	  radx += 0.1;
	}
      rady += 0.1;
    }
}

void	blow_at(t_map *map, t_pos *pos, int size)
{
  int	x;

  x = 0;
  while (x < size)
    {
      blow_rad(map, pos, x);
      x += 1;
    }
}
