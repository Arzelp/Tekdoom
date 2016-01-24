/*
** stretch.c for stretch in /home/alies_a/rendu/gfx_tekdoom
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan 20 14:50:37 2016 alies_a
** Last update Wed Jan 20 14:51:18 2016 alies_a
*/

#include <lapin.h>
#include "doom.h"

void                    stretch(t_bunny_pixelarray *pix,
				const t_bunny_pixelarray *ori)
{
  t_color               c;
  t_bunny_position      pos;
  t_bunny_position      buffer;
  int                   w;
  int                   h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  pos.x = 0;
  pos.y = 0;
  while (pos.y < h)
    {
      buffer.x = ((float)pos.x / w) * (ori->clipable).clip_width;
      buffer.y = ((float)pos.y / h) * (ori->clipable).clip_height;
      c = get_pixel(ori, &buffer);
      tekpixel(pix, &pos, &c);
      pos.x += 1;
      if (!(pos.x < w))
	{
	  pos.y += 1;
	  pos.x = 0;
	}
    }
}
