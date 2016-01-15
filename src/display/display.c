/*
** get_intersec.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jan 13 17:21:08 2016 Arthur Josso
** Last update Fri Jan 15 19:07:39 2016 Arnaud Alies
*/

#include "doom.h"

static void	set_hit_info(t_hit *hit)
{
  hit->blk.x = hit->pt.x;
  hit->blk.y = hit->pt.y;
  hit->blk.z = hit->pt.z;
  if (hit->axe == 'x')
    {
      hit->ratio.x = -MAP(hit->pt.y, hit->blk.y, hit->blk.y + 1, 0, 32);
      hit->ratio.y = -MAP(hit->pt.z, hit->blk.z, hit->blk.z + 1, 0, 32);
    }
  else if (hit->axe == 'y')
    {
      hit->ratio.x = -MAP(hit->pt.x, hit->blk.x, hit->blk.x + 1, 0, 32);
      hit->ratio.y = -MAP(hit->pt.z, hit->blk.z, hit->blk.z + 1, 0, 32);
    }
  else if (hit->axe == 'z')
    {
      hit->ratio.x = -MAP(hit->pt.x, hit->blk.x, hit->blk.x + 1, 0, 32);
      hit->ratio.y = -MAP(hit->pt.y, hit->blk.y, hit->blk.y + 1, 0, 32);
    }
}

static void	set_pix(t_data *data, t_bunny_position *pos)
{
  t_hit		hit;
  t_color	col;
  float		mem;

  get_point(data, pos, &hit);
  set_hit_info(&hit);
  col = get_texture(data, &hit.blk, &hit.ratio);
  mem = hit.norm;
  hit.norm = 1 / hit.norm;
  if (hit.norm < 1)
    {
      col.argb[RED_CMP] = MAP(hit.norm, 0, 1, 20, col.argb[RED_CMP]);
      col.argb[BLUE_CMP] = MAP(hit.norm, 0, 1, 20, col.argb[BLUE_CMP]);
      col.argb[GREEN_CMP] = MAP(hit.norm, 0, 1, 20, col.argb[GREEN_CMP]);
    }
  tekpixel(data->pix, pos, &col);
}

void			display(t_data *data)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < HEIGHT)
    {
      set_pix(data, &pos);
      pos.x += 1;
      if (pos.x > WIDTH)
	{
	  pos.y += 1;
	  pos.x = 0;
	}
    }
}
