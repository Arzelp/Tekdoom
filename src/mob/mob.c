/*
** mob.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 19 10:17:50 2016 Arthur Josso
** Last update Fri Jan 22 14:06:57 2016 Arthur Josso
*/

#include "doom.h"

static void     set_plane(t_data *data, int mob)
{
  data->mob[mob].dir.x = data->mob[mob].pos.x - data->me.pos.x;
  data->mob[mob].dir.y = data->mob[mob].pos.y - data->me.pos.y;
  data->mob[mob].dir.z = 0;
  data->mob[mob].p.a = data->mob[mob].dir.x;
  data->mob[mob].p.b = data->mob[mob].dir.y;
  data->mob[mob].p.c = data->mob[mob].dir.z;
  data->mob[mob].p.d =
    - data->mob[mob].dir.x * data->mob[mob].pos.x
    - data->mob[mob].dir.y * data->mob[mob].pos.y
    - data->mob[mob].dir.z * data->mob[mob].pos.z - PREC;
}

void	gen_mob_plane(t_data *data)
{
  int	i;

  i = 0;
  while (i < NB_MOB)
    set_plane(data, i++);
}
