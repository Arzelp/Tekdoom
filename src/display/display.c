/*
** get_intersec.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jan 13 17:21:08 2016 Arthur Josso
** Last update Fri Jan 15 18:31:19 2016 Arthur Josso
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
  t_color	color;

  get_point(data, pos, &hit);
  set_hit_info(&hit);
  //printf("block : %d %d %d    ratio : %d %d\n", hit.blk.x, hit.blk.y, hit.blk.z, hit.ratio.x, hit.ratio.y);
  //color.full = rand();
  color = get_texture(data, &hit.blk, &hit.ratio);
  tekpixel(data->pix, pos, &color);
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
