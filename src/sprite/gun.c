/*
** gun.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 22 15:24:16 2016 Arthur Josso
** Last update Mon Jan 25 14:47:12 2016 Arthur Josso
*/

#include "doom.h"

static void	fire(t_gun *gun, t_data *data)
{
  static float	frame;
  static char	down;

  if (frame == 0)
    {
      bunny_sound_play(gun->sound);
      hurt_boss(data);
    }
  if (!down && frame <= 5 - gun->speed)
    frame += gun->speed;
  else
    {
      down = 1;
      frame -= gun->speed;
      if (down && frame < 2)
	{
	  gun->fire = 0;
	  down = 0;
	  frame = 0;
	  kill_boss(data);
	}
    }
  gun->frame_pos.x = (int)frame * gun->size.x;
}

void	display_gun(t_bunny_pixelarray *pix, t_gun *gun, t_data *data)
{
  t_bunny_position	pos;
  t_bunny_position	ratio;
  t_color		pixel;

  if (gun->fire)
    fire(gun, data);
  pos.x = gun->beg.x;
  while (pos.x < gun->end.x)
    {
      pos.y = gun->beg.y;
      while (pos.y < gun->end.y)
	{
	  ratio.x = MAP((float)pos.x, gun->beg.x, gun->end.x,
			gun->frame_pos.x, gun->frame_pos.x + gun->size.x);
	  ratio.y = MAP((float)pos.y, gun->beg.y, gun->end.y,
			gun->frame_pos.y, gun->frame_pos.y + gun->size.y);
	  pixel = get_pixel(gun->tex, &ratio);
	  pixel.argb[ALPHA_CMP] = 255;
	  if ((int)pixel.full != TEAL)
	    tekpixel(pix, &pos, &pixel);
	  pos.y++;
	}
      pos.x++;
    }
}
