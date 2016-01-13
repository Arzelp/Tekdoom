/*
** doom.h for doom in /home/alies/rendu/gfx_tekdoom/include
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan 12 16:58:58 2016 Arnaud Alies
** Last update Wed Jan 13 14:14:47 2016 Arnaud Alies
*/

#ifndef DOOM_H_
#define DOOM_H_

#define WIDTH (700)
#define HEIGHT (500)
#define FPS (40)

#define MAP(x, sA, eA, sB, eB) ((((sA - x) / (sA - eA)) * (eB - sB)) + sB)

#include <lapin.h>

typedef	struct s_vec
{
  float	x;
  float	y;
  float z;
} t_vec;

typedef struct s_data
{
  t_bunny_window *win;
  t_bunny_pixelarray *pix;
  const bool *keys;
} t_data;

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

#endif
