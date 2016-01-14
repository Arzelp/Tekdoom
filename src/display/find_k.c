/*
** get_point.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jan 13 19:52:48 2016 Arthur Josso
** Last update Thu Jan 14 21:55:45 2016 Arnaud Alies
*/

#include <math.h>
#include "doom.h"
#include "map.h"

static void	test_x(t_data *data, t_ray *ray, float *k_min)
{
  t_vec		pt;
  float		k;
  int		i;

  i = 0;
  while (i < data->map->head.size)
    {
      k = get_range(ray, 'x', i, &pt);
      pt.x -= data->me.pos.x >= i ? 1 : 0;
      if (pt.x >= 0 && map_check_pos(data->map, &pt)
	  && k >= 0 && k < *k_min)
	*k_min = k;
      i++;
    }
}

#include <stdio.h>

static void     test_y(t_data *data, t_ray *ray, float *k_min)
{
  t_vec         pt;
  float         k;
  int           i;

  i = 0;
  while (i < data->map->head.size)
    {
      k = get_range(ray, 'y', i, &pt);
      if (p)
	{
	  printf("x = %.2f + %.2f * t\n", ray->alpha.x, ray->beta.x);
	  printf("y = %.2f + %.2f * t\n", ray->alpha.y, ray->beta.y);
	  printf("z = %.2f + %.2f * t\n", ray->alpha.z, ray->beta.z);
	  printf("i : %d  y : %.2f\n", i, pt.y);
	}
      pt.y -= data->me.pos.y >= i ? 1 : 0;
      if (pt.y >= 0 && map_check_pos(data->map, &pt)
	  && k >= 0 && k < *k_min)
	*k_min = k;
      i++;
    }
}

static void     test_z(t_data *data, t_ray *ray, float *k_min)
{
  t_vec         pt;
  float         k;
  int           i;

  i = 0;
  while (i < data->map->head.size)
    {
      k = get_range(ray, 'z', i, &pt);
      //printf("i : %d  z : %.2f\n", i, pt.z);
      pt.z -= data->me.pos.z >= i ? 1 : 0;
      if (pt.z >= 0 && map_check_pos(data->map, &pt)
	  && k >= 0 && k < *k_min)
	*k_min = k;
      i++;
    }
}


/*
void    get_ray(t_me *me, t_pos *pos, t_ray *ray)
{
  t_vec scr;

  scr.x = 0.5 * FOV * cos(me->beta) * cos(me->alpha) + me->pos.x;
  scr.y = (((WIDTH / 2) - (float)pos->x) / WIDTH) * FOV * cos(me->beta) * sin(me->alpha) + me->pos.y;
  scr.z = (((HEIGHT / 2) - (float)pos->y) / HEIGHT) * FOV * sin(me->beta) + me->pos.z;
  ray->alpha.x = me->pos.x;
  ray->alpha.y = me->pos.y;
  ray->alpha.z = me->pos.z;
  ray->beta.x = 2 * (ray->alpha.x - scr.x);
  ray->beta.y = 2 * (ray->alpha.y - scr.y);
  ray->beta.z = 2 * (ray->alpha.z - scr.z);
  }
*/
#define DIST 0.5
#define FOV 1

void    get_ray(t_me *me, t_pos *sr, t_ray *ray)
{
  t_vec scr;

  t_vec res;
  t_vec final;

  res.x = DIST;
  res.y = FOV *(((WIDTH / 2) - (float)sr->x) / WIDTH);
  res.z = FOV * (((HEIGHT / 2) - (float)sr->y) / HEIGHT);
  //printf("%f %f %f\n", res.x, res.y, res.z);
  final.x = res.x * cos(me->alpha) - res.y * sin(me->alpha);
  final.y = res.x * sin(me->alpha) + res.y * cos(me->alpha);
  final.z = res.z * sin(me->beta) + res.z * cos(me->beta);
  //printf("%f %f %f\n", final.x, final.y, final.z);

  ray->alpha.x = me->pos.x / 2;
  ray->alpha.y = me->pos.y / 2;
  ray->alpha.z = me->pos.z / 2;
  ray->beta.x = final.x;
  ray->beta.y = final.y;
  ray->beta.z = final.z;
}

void    get_point(t_data *data, t_pos *pos, t_vec *impact, float *norme)
{
  float k_min;
  t_ray ray;
  t_vec vector;

  get_ray(&data->me, pos, &ray);
  k_min = 3 * data->map->head.size;
  test_x(data, &ray, &k_min);
  test_y(data, &ray, &k_min);
  test_z(data, &ray, &k_min);
  calc_pos(impact, &ray, k_min);
  vector.x = impact->x -data->me.pos.x;
  vector.y = impact->y - data->me.pos.y;
  vector.z = impact->z - data->me.pos.z;
  *norme = sqrt(vector.x * vector.x
	       + vector.y * vector.y
	       + vector.z * vector.z);
}
