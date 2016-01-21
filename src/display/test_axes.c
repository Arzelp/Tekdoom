/*
** test_axes.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 19 16:02:18 2016 Arthur Josso
** Last update Tue Jan 19 16:06:39 2016 Arthur Josso
*/

#include "doom.h"

void     test_x(t_data *data, t_ray *ray, t_hit *hit)
{
  t_vec         pt;
  float         k;
  float         i;

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

void     test_y(t_data *data, t_ray *ray, t_hit *hit)
{
  t_vec         pt;
  float         k;
  float         i;

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

void     test_z(t_data *data, t_ray *ray, t_hit *hit)
{
  t_vec         pt;
  float         k;
  float         i;

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
