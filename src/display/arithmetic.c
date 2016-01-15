/*
** get_point_on_plane.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jan 13 14:16:07 2016 Arthur Josso
** Last update Fri Jan 15 19:02:19 2016 Arthur Josso
*/

#include "doom.h"

static float	get_k(t_ray *ray, char plane, float lvl)
{
  if (plane == 'x')
    {
      if (ray->beta.x == 0)
	return (MAX);
      return ((ray->alpha.x + lvl) / ray->beta.x);
    }
  else if (plane == 'y')
    {
      if (ray->beta.y == 0)
	return (MAX);
      return ((ray->alpha.y + lvl) / ray->beta.y);
    }
  else if (plane == 'z')
    {
      if (ray->beta.z == 0)
	return (MAX);
      return ((ray->alpha.z + lvl) / ray->beta.z);
    }
  return (0);
}

void	calc_pos(t_vec *result, t_ray *param, float k)
{
  result->x = LIM(-param->alpha.x + k * param->beta.x);
  result->y = LIM(-param->alpha.y + k * param->beta.y);
  result->z = LIM(-param->alpha.z + k * param->beta.z);
}

float	get_range(t_ray *ray, char plane, float lvl, t_vec *point)
{
  float	k;

  k = get_k(ray, plane, lvl);
  calc_pos(point, ray, k);
  return (k);
}
