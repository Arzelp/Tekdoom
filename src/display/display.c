/*
** get_intersec.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jan 13 17:21:08 2016 Arthur Josso
** Last update Fri Jan 15 10:14:55 2016 Arthur Josso
*/

#include "doom.h"

#define LOIN (80)

void	set_pix(t_data *data, t_pos *pos)
{
  t_vec	impact;
  float	norme;
  char	col;
  t_color color;
  t_bunny_position p;

  get_point(data, pos, &impact, &norme);
  if (norme > LOIN)
    norme = LOIN;
  col = 255 - MAP(norme, 0, LOIN, 0, 255);
  color.argb[RED_CMP] = col;
  color.argb[BLUE_CMP] = col;
  color.argb[GREEN_CMP] = col;
  p.x = pos->x;
  p.y = pos->y;
  tekpixel(data->pix, &p, &color);
}

void	display(t_data *data)
{
  t_pos pos;

  pos.x = 0;
  while (pos.x < WIDTH)
    {
      pos.y = 0;
      while (pos.y < HEIGHT)
	{
	  set_pix(data, &pos);
	  pos.y++;
	}
      pos.x++;
    }
}
