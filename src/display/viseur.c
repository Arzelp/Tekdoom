/*
** viseur.c for viseur in /src/display/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Jan 19 16:24:59 2016 Frederic ODDOU
** Last update Tue Jan 19 16:24:59 2016 Frederic ODDOU
*/

#include "doom.h"

void			viseur(t_data *data)
{
  t_bunny_position	pos;
  int			i;
  t_color		color;

  i = 0;
  color.full = 0xa5a5a5;
  pos.x = (data->pix->clipable).clip_width / 2 - 7;
  pos.y = (data->pix->clipable).clip_height / 2;
  while (i < 14)
    {
      pos.x += 1;
      tekpixel(data->pix, &pos, &color);
      i++;
    }
  i = 0;
  pos.x = (data->pix->clipable).clip_width / 2;
  pos.y = (data->pix->clipable).clip_height / 2 - 7;
  while (i < 14)
    {
      pos.y += 1;
      tekpixel(data->pix, &pos, &color);
      i++;
    }
}
