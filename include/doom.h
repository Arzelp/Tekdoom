/*
** doom.h for doom in /home/alies/rendu/gfx_tekdoom/include
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Tue Jan 12 16:58:58 2016 Arnaud Alies
** Last update Thu Jan 21 17:20:56 2016 alies_a
*/

#ifndef DOOM_H_
#define DOOM_H_

#define WIDTH (320)
#define HEIGHT (200)
#define FPS (40)
#define FOVX (1)
#define FOVY (0.7)
#define DIST (0.5)

#define MAP(x, sA, eA, sB, eB) ((((sA - x) / (sA - eA)) * (eB - sB)) + sB)
#define ABS(x) ((x) < 0 ? -(x) : (x))

#include <lapin.h>
#include "map.h"

typedef struct s_vec
{
  float x;
  float y;
  float z;
} t_vec;

typedef struct s_plane
{
  float	a;
  float	b;
  float	c;
  float	d;
} t_plane;

typedef struct s_me
{
  t_vec		pos;
  int		inair;
  float		fall;
  float		sprint;
  float		crowd;
  float		alpha;
  float		beta;
  int		fly;
  float		speedfront;
  float		speedside;
} t_me;

typedef struct s_mob
{
  t_vec			pos;
  t_vec			size;
  t_bunny_pixelarray	*tex;
  t_plane		p;
  t_vec			dir;
} t_mob;

typedef struct s_select
{
  int selected;
  int open;
} t_select;

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*texture;
  const bool		*keys;
  t_me			me;
  t_mob			*mob;
  t_map			*map;
  t_select		select;
} t_data;

/*
** Display
*/

#define MAX (99)
#define LIM(x) ((x) < -(MAX) ? -(MAX) : ((x) > MAX ? MAX : (x)))
#define VIEW_DIST (15)
#define PREC (0.0001)
#define NB_MOB (1)

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
  t_color		pix;
} t_hit;

void    display(t_data *data);
void    test_mobs(t_data *data, t_ray *ray, t_hit *hit);

void	test_x(t_data *data, t_ray *ray, t_hit *hit);
void	test_y(t_data *data, t_ray *ray, t_hit *hit);
void	test_z(t_data *data, t_ray *ray, t_hit *hit);

void    get_point(t_data *data, t_bunny_position *pos, t_hit *hit);
float   get_range(t_ray *ray, char plane, float lvl, t_vec *point);
void    calc_pos(t_vec *result, t_ray *param, float k);
int     map_check_pos(t_map *map, t_vec *vec);

void	stretch(t_bunny_pixelarray *pix,
		const t_bunny_pixelarray *ori);

/*
** Core
*/

t_color	get_pixel(const t_bunny_pixelarray *pix,
		  t_bunny_position *pos);

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

/*
** Initialize
*/

int	init_all(t_data *data, int ac, char **av);

/*
** Texture
*/

#define MAX_TEXT (96)

void	show_textures(t_data *data);

t_color	get_texture(t_data *data,
		    t_pos *block_x,
		    t_bunny_position *pos);

#endif
