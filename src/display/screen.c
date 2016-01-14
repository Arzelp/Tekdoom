/*
** screen.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jan 14 18:13:58 2016 Arthur Josso
** Last update Thu Jan 14 20:01:23 2016 Arthur Josso
*/

#include <math.h>
#include "doom.h"

static void	rot_x(t_vec *vec, float angle)
{
  float mem;

  mem = vec->y;
  vec->y = mem * cos(angle) + vec->z * -sin(angle);
  vec->z = mem * sin(angle) + vec->z * cos(angle);
}

static void	rot_y(t_vec *vec, float angle)
{
  float	mem;

  mem = vec->x;
  vec->x = mem * cos(angle) + vec->z * sin(angle);
  vec->z = mem * -sin(angle) + vec->z * cos(angle);
}

static void	rot_z(t_vec *vec, float angle)
{
  float	mem;

  mem = vec->x;
  vec->x = mem * cos(angle) + vec->y * -sin(angle);
  vec->y = mem * sin(angle) + vec->y * cos(angle);
}
/*
void	get_ray(t_me *me, t_pos *pos, t_ray *ray)
{
  t_vec scr;

  scr.x = DIST;
  scr.y = WIDTH / 2.0 - pos->x;
  scr.z = HEIGHT / 2.0 - pos->y;
  rot_x(&scr, me->alpha);
  rot_y(&scr, 0);
  rot_z(&scr, me->beta);
  ray->alpha.x = me->pos.x;
  ray->alpha.y = me->pos.y;
  ray->alpha.z = me->pos.z;
  ray->beta.x = 2 * (ray->alpha.x - scr.x);
  ray->beta.y = 2 * (ray->alpha.y - scr.y);
  ray->beta.z = 2 * (ray->alpha.z - scr.z);
}
*/
