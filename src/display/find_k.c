/*
** get_point.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jan 13 19:52:48 2016 Arthur Josso
** Last update Fri Jan 15 18:12:51 2016 Arthur Josso
*/

#include <math.h>
#include "doom.h"
#include "map.h"

#define LOLMAGICBITCH (0.0001)

static void	test_x(t_data *data, t_ray *ray, t_hit *hit)
{
  t_vec		pt;
  float		k;
  float		i;

  i = LOLMAGICBITCH;
  while (i < data->map->head.size)
    {
      k = get_range(ray, 'x', i, &pt);
      pt.x -= data->me.pos.x >= i ? 1 : 0;
      if (pt.x >= 0 && map_check_pos(data->map, &pt)
	  && k >= 0 && k < hit->norm)
	{
	  hit->norm = k;
	  hit->axe = 'x';
	  hit->pt = pt;
	}
      i++;
    }
}

static void     test_y(t_data *data, t_ray *ray, t_hit *hit)
{
  t_vec         pt;
  float         k;
  float		i;

  i = LOLMAGICBITCH;
  while (i < data->map->head.size)
    {
      k = get_range(ray, 'y', i, &pt);
      pt.y -= data->me.pos.y >= i ? 1 : 0;
      if (pt.y >= 0 && map_check_pos(data->map, &pt)
	  && k >= 0 && k < hit->norm)
	{
	  hit->norm = k;
	  hit->axe = 'y';
	  hit->pt = pt;
	}
      i++;
    }
}

static void     test_z(t_data *data, t_ray *ray, t_hit *hit)
{
  t_vec         pt;
  float         k;
  float		i;

  i = LOLMAGICBITCH;
  while (i < data->map->head.size)
    {
      k = get_range(ray, 'z', i, &pt);
      pt.z -= data->me.pos.z >= i ? 1 : 0;
      if (pt.z >= 0 && map_check_pos(data->map, &pt)
	  && k >= 0 && k < hit->norm)
	{
	  hit->norm = k;
	  hit->axe = 'z';
	  hit->pt = pt;
	}
      i++;
    }
}

static void    get_ray(t_me *me, t_bunny_position *sr, t_ray *ray)
{
  t_vec res;

  res.x = DIST;
  res.y = FOV * (((WIDTH / 2) - (float)sr->x) / WIDTH);
  res.z = FOV * (((HEIGHT / 2) - (float)sr->y) / HEIGHT);
  ray->beta.x = res.x * cos(me->alpha) - res.y * sin(me->alpha);
  ray->beta.y = res.x * sin(me->alpha) + res.y * cos(me->alpha);
  ray->beta.z = res.z + me->beta;
  ray->alpha.x = -me->pos.x;
  ray->alpha.y = -me->pos.y;
  ray->alpha.z = -me->pos.z;
}

void    get_point(t_data *data, t_bunny_position *pos, t_hit *hit)
{
  t_ray ray;

  get_ray(&data->me, pos, &ray);
  hit->norm = 3 * data->map->head.size;
  test_x(data, &ray, hit);
  test_y(data, &ray, hit);
  test_z(data, &ray, hit);
}
