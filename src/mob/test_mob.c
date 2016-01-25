/*
** mob_get_fct.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jan 21 19:14:30 2016 Arthur Josso
** Last update Mon Jan 25 12:06:58 2016 Arthur Josso
*/

#include <math.h>
#include "doom.h"

static float    get_k(t_data *data, t_ray *ray, int mob)
{
  float		denom;
  float		nom;

  denom = data->mob[mob].p.a * ray->beta.x
    + data->mob[mob].p.b * ray->beta.y
    + data->mob[mob].p.c * ray->beta.z;
  if (denom == 0)
    return (MAX);
  nom =
    - data->mob[mob].p.a * -ray->alpha.x
    - data->mob[mob].p.b * -ray->alpha.y
    - data->mob[mob].p.c * -ray->alpha.z
    - data->mob[mob].p.d;
  return (nom / denom);
}

static float    get_dist(t_vec *o, t_vec *a, t_vec *b)
{
  float		ret;
  float		teta_a;
  float		teta_b;

  ret = sqrt((o->x - b->x) * (o->x - b->x)
	     + (o->y - b->y) * (o->y - b->y)
	     - (o->x - a->x) * (o->x - a->x)
	     - (o->y - a->y) * (o->y - a->y));
  teta_a = atan2(a->x, a->y);
  teta_b = atan2(b->x, b->y);
  if (teta_a > teta_b)
    ret *= -1;
  return (ret);
}

static t_color          get_color(t_data *data, int mob, t_vec *pt)
{
  t_color               col;
  t_bunny_position      ratio;
  float                 x;

  x = get_dist(&data->me.pos, &data->mob[mob].pos, pt);
  if (ABS(x) > data->mob[mob].size.x
      || pt->z > data->mob[mob].size.y
      || pt->z < 0)
    col.full = TEAL;
  else
    {
      ratio.x = MAP(x, -data->mob[mob].size.x, data->mob[mob].size.x,
		    0, data->mob[mob].tex->clipable.clip_width);
      ratio.y = MAP(pt->z, data->mob[mob].pos.z,
		    data->mob[mob].size.y + data->mob[mob].pos.z,
		    0, data->mob[mob].tex->clipable.clip_height);
      ratio.y = data->mob[mob].tex->clipable.clip_height - ratio.y;
      col = get_pixel(data->mob[mob].tex, &ratio);
      col.argb[ALPHA_CMP] = 255;
    }
  return (col);
}

static void	test_mob(t_data *data, t_ray *ray, t_hit *hit, int mob)
{
  float		k;
  t_vec		pt;
  t_color	pix;

  k = get_k(data, ray, mob);
  calc_pos(&pt, ray, k);
  pix = get_color(data, mob, &pt);
  if (k >= 0 && k < hit->norm
      && pt.x < hit->max.x && pt.y < hit->max.y
      && pt.x > hit->min.x && pt.y > hit->min.y
      && (int)pix.full != TEAL)
    {
      hit->norm = k;
      hit->axe = 'm';
      hit->pt = pt;
      hit->pix = pix;
      hit->mob = mob;
    }
}

void    test_mobs(t_data *data, t_ray *ray, t_hit *hit)
{
  int   i;

  i = 0;
  while (i < NB_MOB)
    {
      test_mob(data, ray, hit, i);
      i++;
    }
}
