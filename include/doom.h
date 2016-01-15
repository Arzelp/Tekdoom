/*
** doom.h for doom in /home/alies/rendu/gfx_tekdoom/include
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan 12 16:58:58 2016 Arnaud Alies
** Last update Fri Jan 15 10:30:02 2016 Arnaud Alies
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

int p;

typedef struct s_block
{
  uint32_t x;
} __attribute__((packed)) t_block;

typedef struct s_map_head
{
  uint32_t	version;
  int		size;
  uint32_t	offset;
} __attribute__((packed)) t_map_head;

/*
** map file format:
** <header>
** <textures> textures starts just after header
** <blocks> blocks start after offset defined in the header
*/

typedef struct s_map
{
  t_map_head head;
  t_block *blocks;
} __attribute__((packed)) t_map;

typedef struct s_pos
{
  int x;
  int y;
  int z;
} t_pos;

typedef struct s_vec
{
  float x;
  float y;
  float z;
} t_vec;

typedef struct s_me
{
  t_vec	pos;
  float	alpha;
  float	beta;
} t_me;

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  const bool		*keys;
  t_me			me;
  t_map			*map;
} t_data;

/*
** Display
*/

#define MAX (99)
#define LIM(x) ((x) < -(MAX) ? -(MAX) : ((x) > MAX ? MAX : (x)))
//#define LIM(x) ((x))

typedef struct s_ray
{
  t_vec	alpha;
  t_vec	beta;
} t_ray;

void    display(t_data *data);

//void    get_ray(t_me *me, t_pos *pos, t_ray *ray);
void    get_point(t_data *data, t_pos *pos, t_vec *impact, float *norme);
float   get_range(t_ray *ray, char plane, float lvl, t_vec *point);
void    calc_pos(t_vec *result, t_ray *param, float k);

/*
** Core
*/

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

#endif
