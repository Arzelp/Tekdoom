/*
** show_texture.c for show in /home/alies_a/rendu/gfx_tekdoom
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan 20 16:19:07 2016 alies_a
** Last update Wed Jan 20 17:13:05 2016 alies_a
*/

#include <lapin.h>
#include "doom.h"

static t_bunny_pixelarray	*copy_pix(const t_bunny_pixelarray *pix)
{
  t_bunny_pixelarray		*res;
  int                   	w;
  int                   	h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  res = bunny_new_pixelarray(w, h);
  if (res == NULL)
    return (NULL);
  stretch(res, pix);
  return (res);
}

static void		draw_square(t_bunny_pixelarray *pix,
				    t_bunny_position start,
				    int size,
				    int margin)
{
  t_bunny_position      pos;
  t_color               c;

  c.full = WHITE;
  pos.x = start.x;
  pos.y = start.y;
  while (pos.y < start.y + size)
    {
      if (pos.x < start.x + margin || pos.x > start.x + size - margin ||
	  pos.y < start.y + margin || pos.y > start.y + size - margin)
	tekpixel(pix, &pos, &c);
      pos.x += 1;
      if (pos.x > start.x + size)
	{
	  pos.y += 1;
	  pos.x = start.x;
	}
    }
}

static void		set_selected(t_bunny_pixelarray *pix,
				     int selected)
{
  t_bunny_position	start;
  
  start.x = (selected % 16) * 32;
  start.y = (selected / 16) * 32;
  draw_square(pix, start, 32, 4);
}

void                    show_textures(t_data *data)
{
  int                   margin;
  t_bunny_pixelarray    *buffer;
  t_bunny_pixelarray    *new;
  t_bunny_position      zero;

  margin = 15;
  zero.x = margin;
  zero.y = margin;
  if ((buffer = copy_pix(data->texture)) == NULL)
    return ;
  set_selected(buffer, (data->select).selected);
  if ((new = bunny_new_pixelarray(WIDTH - margin * 2,
				  HEIGHT - margin * 2)) == NULL)
    return ;
  stretch(new, buffer);
  bunny_blit(&((data->win)->buffer), &((new)->clipable), &zero);
  bunny_delete_clipable(&((new)->clipable));
  bunny_delete_clipable(&((buffer)->clipable));
}
