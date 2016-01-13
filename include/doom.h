/*
** doom.h for doom in /home/alies/rendu/gfx_tekdoom/include
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan 12 16:58:58 2016 Arnaud Alies
** Last update Wed Jan 13 19:32:14 2016 Arthur Josso
*/

#ifndef DOOM_H_
#define DOOM_H_

#define WIDTH (700)
#define HEIGHT (500)
#define FPS (40)

#define MAP(x, sA, eA, sB, eB) ((((sA - x) / (sA - eA)) * (eB - sB)) + sB)
#define ABS(x) ((x) < 0 ? -(x) : (x))

#include <lapin.h>

typedef struct s_vec
{
  float x;
  float y;
  float z;
} t_vec;

typedef struct s_me
{
  t_vec	pos;
  int   alpha;
  int	beta;
} t_me;

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  const bool		*keys;
  t_me			me;
} t_data;

/*
** get_point_on_plane.c
*/

#define MAX (99)
#define LIM(x) ((x) < -(MAX) ? -(MAX) : ((x) > MAX ? MAX : (x)))

typedef struct t_pos
{
  int x;
  int y;
} t_pos;

typedef struct s_ray
{
  t_vec	alpha;
  t_vec	beta;
} t_ray;

void    get_point(t_ray *ray, char plane, int lvl, t_vec *point);

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

#endif
