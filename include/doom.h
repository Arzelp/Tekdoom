/*
** doom.h for doom in /home/alies/rendu/gfx_tekdoom/include
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Tue Jan 12 16:58:58 2016 Arnaud Alies
** Last update Mon Jan 18 00:50:50 2016 Paskal Arzel
*/

#ifndef DOOM_H_
#define DOOM_H_

#define WIDTH (320)
#define HEIGHT (200)
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
  float		inair;
  float		fall;
} t_jump;

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*texture;
  const bool		*keys;
  t_me			me;
  float			sprint;
  t_jump		*jump;
  t_map			*map;
} t_data;

/*
** Display
*/

#define MAX (99)
#define LIM(x) ((x) < -(MAX) ? -(MAX) : ((x) > MAX ? MAX : (x)))
#define VIEW_DIST (15)
#define PREC (0.0001)

typedef struct s_ray
{
  t_vec	alpha;
  t_vec	beta;
} t_ray;

typedef struct s_hit
{
  t_vec                 pt;
  char                  axe;
  float                 norm;
  t_bunny_position      ratio;
  t_pos                 blk;
  t_pos                 min;
  t_pos                 max;
} t_hit;

void    display(t_data *data);

void    get_point(t_data *data, t_bunny_position *pos, t_hit *hit);
float   get_range(t_ray *ray, char plane, float lvl, t_vec *point);
void    calc_pos(t_vec *result, t_ray *param, float k);

t_color	get_texture(t_data *data,
		    t_pos *block_x,
		    t_bunny_position *pos);

/*
** Core
*/

t_color	get_pixel(t_bunny_pixelarray *pix,
		  t_bunny_position *pos);

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

#endif
