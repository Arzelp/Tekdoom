/*
** drawjauge.c for drawjauge.c in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/gfx_tekdoom/gfx_tekdoom/src/control/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Jan 18 00:57:50 2016 Paskal Arzel
** Last update Mon Jan 18 01:35:39 2016 Paskal Arzel
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "map.h"
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

int	filljauge(t_data *data, t_bunny_pixelarray *pix, t_color *color)
{
  t_bunny_position	pos;
  t_bunny_position	pos2;

  color->full = 0x0066CC;
  if (data->sprint == 0)
    return (0);
  pos.x = 13;
  pos2.x = data->sprint / 1.295;
  pos.y = HEIGHT - 17;
  pos2.y = HEIGHT - 8;
  drawsquare(pix, pos, pos2, color);
  return (0);
}

int	makelines(t_bunny_pixelarray *pix, t_color *color)
{
  t_bunny_position	pos;
  t_bunny_position	pos2;

  pos.x = 10;
  pos2.x = 80;
  pos.y = HEIGHT - 20;
  pos2.y = HEIGHT - 18;
  color->full = 0;
  drawsquare(pix, pos, pos2, color);
  pos.y = HEIGHT - 7;
  pos2.y = HEIGHT - 5;
  drawsquare(pix, pos, pos2, color);
  pos2.x = 12;
  pos.y = HEIGHT - 20;
  drawsquare(pix, pos, pos2, color);
  pos.x = 78;
  pos2.x = 80;
  drawsquare(pix, pos, pos2, color);
  return (0);
}

int	drawjauge(t_data *data, t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  t_color 		color;

  if (WIDTH >= 200 && HEIGHT >= 200)
    {
      makelines(pix, &color);
      filljauge(data, pix, &color);
    }
  return (0);
}
