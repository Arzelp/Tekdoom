/*
** get_point.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jan 13 19:52:48 2016 Arthur Josso
** Last update Thu Jan 21 16:02:13 2016 alies_a
*/

#include <math.h>
#include "doom.h"
#include "map.h"

static void	test_x(t_data *data, t_ray *ray, t_hit *hit)
{
  t_vec		pt;
  float		k;
  float		i;

  i = hit->min.x;
  i += PREC;
  while (i < hit->max.x)
    {
      k = get_range(ray, 'x', i, &pt);
      pt.x -= data->me.pos.x >= i ? 1 : 0;
      if (map_check_pos(data->map, &pt)
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

  i = hit->min.y;
  i += PREC;
  while (i < hit->max.y)
    {
      k = get_range(ray, 'y', i, &pt);
      pt.y -= data->me.pos.y >= i ? 1 : 0;
      if (map_check_pos(data->map, &pt)
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

  i = hit->min.z;
  i += PREC;
  while (i < hit->max.z)
    {
      k = get_range(ray, 'z', i, &pt);
      pt.z -= data->me.pos.z >= i ? 1 : 0;
      if (map_check_pos(data->map, &pt)
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
  res.y = FOVX * (((WIDTH / 2) - (float)sr->x) / WIDTH);
  res.z = FOVY * (((HEIGHT / 2) - (float)sr->y) / HEIGHT);
  ray->beta.x = res.x * cos(me->alpha) - res.y * sin(me->alpha);
  ray->beta.y = res.x * sin(me->alpha) + res.y * cos(me->alpha);
  ray->beta.z = res.z + me->beta;
  ray->alpha.x = -me->pos.x;
  ray->alpha.y = -me->pos.y;
  ray->alpha.z = -me->pos.z;
}

void	set_lim(float alpha, float beta, int *min, int *max)
{
  if (beta < 0)
    {
      *min = - alpha - VIEW_DIST + 1;
      *max = - alpha + 1;
    }
  else
    {
      *min = -alpha;
      *max = -alpha + VIEW_DIST;
    }
}

void	get_lim(t_ray *ray, t_hit *hit)
{
  set_lim(ray->alpha.x, ray->beta.x, &hit->min.x, &hit->max.x);
  set_lim(ray->alpha.y, ray->beta.y, &hit->min.y, &hit->max.y);
  set_lim(ray->alpha.z, ray->beta.z, &hit->min.z, &hit->max.z);
}

void    get_point(t_data *data, t_bunny_position *pos, t_hit *hit)
{
  t_ray ray;

  get_ray(&data->me, pos, &ray);
  get_lim(&ray, hit);
  hit->norm = 3 * data->map->head.size;
  hit->axe = '0';
  test_x(data, &ray, hit);
  test_y(data, &ray, hit);
  test_z(data, &ray, hit);
}
