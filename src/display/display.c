/*
** get_intersec.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jan 13 17:21:08 2016 Arthur Josso
** Last update Fri Jan 15 14:30:11 2016 Arnaud Alies
*/

#include "doom.h"

#define LOIN (10)

void	set_pix(t_data *data, t_bunny_position *pos)
{
  t_vec	impact;
  float	norme;
  char	col;
  t_color color;

  get_point(data, pos, &impact, &norme);
  norme = (norme > LOIN ? LOIN : norme);
  col = 255 - MAP(norme, 0, LOIN, 0, 255);
  color.argb[RED_CMP] = col;
  color.argb[BLUE_CMP] = col;
  color.argb[GREEN_CMP] = col;
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
