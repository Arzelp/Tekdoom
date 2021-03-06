/*
** get_intersec.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
**
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
**
** Started on  Wed Jan 13 17:21:08 2016 Arthur Josso
** Last update Tue Jan 26 19:05:52 2016 Frederic ODDOU
*/

#include <pthread.h>
#include "doom.h"

void	set_hit_info(t_hit *hit)
{
  hit->blk.x = hit->pt.x;
  hit->blk.y = hit->pt.y;
  hit->blk.z = hit->pt.z;
  if (hit->axe == 'x')
    {
      hit->ratio.x = -MAP(hit->pt.y, hit->blk.y, hit->blk.y + 1, 0, 32);
      hit->ratio.y = -MAP(hit->pt.z, hit->blk.z, hit->blk.z + 1, 0, 32);
    }
  else if (hit->axe == 'y')
    {
      hit->ratio.x = -MAP(hit->pt.x, hit->blk.x, hit->blk.x + 1, 0, 32);
      hit->ratio.y = -MAP(hit->pt.z, hit->blk.z, hit->blk.z + 1, 0, 32);
    }
  else if (hit->axe == 'z')
    {
      hit->ratio.x = -MAP(hit->pt.x, hit->blk.x, hit->blk.x + 1, 0, 32);
      hit->ratio.y = -MAP(hit->pt.y, hit->blk.y, hit->blk.y + 1, 0, 32);
    }
}

static void	set_pix(t_data *data, t_bunny_position *pos)
{
  t_hit		hit;
  float		d_viewdist;

  get_point(data, pos, &hit);
  if (hit.axe == '0')
    hit.pix.full = BLACK;
  else if (hit.axe != 'm')
    {
      set_hit_info(&hit);
      hit.pix = get_texture(data, &hit.blk, &hit.ratio);
      d_viewdist = 1.7 * VIEW_DIST;
      if (hit.norm > d_viewdist)
	hit.norm = d_viewdist;
      hit.norm = d_viewdist - hit.norm;
      hit.pix.argb[RED_CMP] =
	MAP(hit.norm, 0, d_viewdist, 0, hit.pix.argb[RED_CMP]);
      hit.pix.argb[BLUE_CMP] =
	MAP(hit.norm, 0, d_viewdist, 0, hit.pix.argb[BLUE_CMP]);
      hit.pix.argb[GREEN_CMP] =
	MAP(hit.norm, 0, d_viewdist, 0, hit.pix.argb[GREEN_CMP]);
    }
  if (pos->x == WIDTH / 2 && pos->y == HEIGHT / 2)
    data->me.pointed_mob = hit.axe == 'm' ? hit.mob : -1;
  tekpixel(data->pix, pos, &hit.pix);
}

static void *slice1(void *data_pt)
{
  t_bunny_position      pos;
  t_data		*data;

  data = (t_data*)data_pt;
  pos.x = 0;
  pos.y = 0;
  while (pos.y < HEIGHT / 2)
    {
      set_pix(data, &pos);
      pos.x += 1;
      if (pos.x > WIDTH)
	{
	  pos.y += 1;
	  pos.x = 0;
	}
    }
  return (NULL);
}

static void *slice2(void *data_pt)
{
  t_bunny_position      pos;
  t_data		*data;

  data = (t_data*)data_pt;
  pos.x = 0;
  pos.y = HEIGHT / 2;
  while (pos.y < HEIGHT)
    {
      set_pix(data, &pos);
      pos.x += 1;
      if (pos.x > WIDTH)
	{
	  pos.y += 1;
	  pos.x = 0;
	}
    }
  return (NULL);
}

void			display(t_data *data)
{
  pthread_t ta;
  pthread_t tb;

  gen_mob_plane(data);
  (data->me).pos.z -= (data->me).crowd;
  pthread_create (&ta, NULL, slice1, (void*)data);
  pthread_create (&tb, NULL, slice2, (void*)data);
  pthread_join(ta, NULL);
  pthread_join(tb, NULL);
  (data->me).pos.z += (data->me).crowd;
  viseur(data);
}
