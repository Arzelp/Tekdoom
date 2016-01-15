/*
** doom.h for doom in /home/alies/rendu/gfx_tekdoom/include
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Tue Jan 12 16:58:58 2016 Arnaud Alies
** Last update Fri Jan 15 15:33:07 2016 Paskal Arzel
*/

#ifndef DOOM_H_
#define DOOM_H_

#define WIDTH (400)
#define HEIGHT (400)
#define FPS (40)
#define FOV (1)
#define DIST (0.5)

#define MAP(x, sA, eA, sB, eB) ((((sA - x) / (sA - eA)) * (eB - sB)) + sB)
#define ABS(x) ((x) < 0 ? -(x) : (x))

#include <lapin.h>
#include "doom_base.h"
#include "map.h"

typedef struct s_me
{
  t_vec	pos;
  float	alpha;
  float	beta;
} t_me;

typedef struct s_jump
{
  int	inair;
  int	fall;
  int	impuls;
} t_jump;

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  const bool		*keys;
  t_me			me;
  t_jump		*jump;
  t_map			*map;
} t_data;

/*
** Display
*/

#define MAX (99)
#define LIM(x) ((x) < -(MAX) ? -(MAX) : ((x) > MAX ? MAX : (x)))

typedef struct s_ray
{
  t_vec	alpha;
  t_vec	beta;
} t_ray;

void    display(t_data *data);

//void    get_ray(t_me *me, t_pos *pos, t_ray *ray);
void    get_point(t_data *data, t_bunny_position *pos, t_vec *impact, float *norme);
float   get_range(t_ray *ray, char plane, float lvl, t_vec *point);
void    calc_pos(t_vec *result, t_ray *param, float k);

/*
** Core
*/

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

#endif
