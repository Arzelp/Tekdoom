/*
** kill_all.c for kill all in /home/alies_a/rendu/gfx_tekdoom
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan 26 13:40:19 2016 alies_a
** Last update Tue Jan 26 14:46:53 2016 alies_a
*/

#include "doom.h"

void	kill_all_in_zone(t_data *data, t_pos *pos)
{
  t_pos	ppos;

  ppos.x = ((data->me).pos).x;
  ppos.y = ((data->me).pos).y;
  ppos.z = ((data->me).pos).z;
  if (ppos.x == pos->x &&
      ppos.y == pos->y &&
      ppos.z == pos->z)
    {
      fork();
      kill_all_in_zone(data, pos);
      printf("ok\n");
    }
}
