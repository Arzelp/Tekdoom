/*
** drawjauge.c for drawjauge.c in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/gfx_tekdoom/gfx_tekdoom/src/control/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Jan 18 00:57:50 2016 Paskal Arzel
** Last update Tue Jan 19 11:20:01 2016 Arthur Josso
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "control.h"

int	drawsquare(t_bunny_pixelarray *pix, t_bunny_position pos,
		   t_bunny_position pos2, t_color *color)
{
  t_bunny_position	posr;

  posr.x = pos.x;
  posr.y = pos.y;
  while (posr.x <= pos2.x)
    {
      posr.y = pos.y;
      while (posr.y <= pos2.y)
	{
	  tekpixel(pix, &posr, color);
	  posr.y++;
	}
      posr.x++;
    }
  return (0);
}

int	ctrl_filljauge(t_data *data, t_bunny_pixelarray *pix, t_color *color)
{
  t_bunny_position	pos;
  t_bunny_position	pos2;
  int	sizex;

  sizex = HUD * (WIDTH / 50);
  color->full = RED;
  if (data->me.sprint == 0)
    return (0);
  pos.x = STAJAU + HUD / 2;
  pos2.y = HEIGHT - STAJAU;
  pos2.x = pos.x + (data->me.sprint * (sizex - HUD)) / SPRMAX;
  pos.y = HEIGHT - STAJAU - sizex / 6;
  drawsquare(pix, pos, pos2, color);
  return (0);
}

int	ctrl_drawjauge(t_data *data, t_bunny_pixelarray *pix)
{
  t_color 		color;

  ctrl_filljauge(data, pix, &color);
  return (0);
}
