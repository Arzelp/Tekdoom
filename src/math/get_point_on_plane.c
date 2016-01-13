/*
** get_point_on_plane.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jan 13 14:16:07 2016 Arthur Josso
** Last update Wed Jan 13 15:09:25 2016 Arthur Josso
*/

#include "doom.h"

static float	get_t(t_ray *ray, char plane, int lvl)
{
  if (plane == 'x')
    {
      if (ray->beta.x == 0)
	return (MAX);
      return (LIM(-((ray->alpha.x + lvl) / ray->beta.x)));
    }
  else if (plane == 'y')
    {
      if (ray->beta.y == 0)
	return (MAX);
      return (LIM(-((ray->alpha.y + lvl) / ray->beta.y)));
    }
  else if (plane == 'z')
    {
      if (ray->beta.z == 0)
	return (MAX);
      return (LIM(-((ray->alpha.z + lvl) / ray->beta.z)));
    }
}

void	get_point(t_ray *ray, char plane, int lvl, t_vec *point)
{
  float	t;

  t = get_t(ray, plane, lvl);
  point->x = LIM(ray->alpha.x + t * ray->beta.x);
  point->y = LIM(ray->alpha.y + t * ray->beta.y);
  point->z = LIM(ray->alpha.z + t * ray->beta.z);
}
