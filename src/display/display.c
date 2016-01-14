/*
** get_intersec.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jan 13 17:21:08 2016 Arthur Josso
** Last update Thu Jan 14 20:11:07 2016 Arthur Josso
*/

#include "doom.h"

void	set_pix(t_data *data, t_pos *pos)
{
  t_vec	impact;
  float	norme;
  char	col;
  t_color color;
  t_bunny_position p;

  get_point(data, pos, &impact, &norme);
  if (norme > 20)
    norme = 20;
  col = 255 - MAP(norme, 0, 20, 0, 255);
  /*
  if (norme > 60)
    printf("impact : x : %.3f y : %.3f z : %.3f\nx : %d y : %d\n", impact.x,
	   impact.y, impact.z, pos->x, pos->y);
  */
  //col = norme > 60 ? 0 : 255;
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
