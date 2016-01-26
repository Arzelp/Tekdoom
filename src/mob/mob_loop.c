/*
** mob_loop.c for mob loop in /home/alies_a/rendu/gfx_tekdoom
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan 21 17:57:17 2016 alies_a
** Last update Tue Jan 26 10:28:53 2016 alies_a
*/

#include "doom.h"

static void	mob_attack(t_data *data, t_mob *mob)
{
  t_pos		pos;

  pos.x = (mob->pos).x;
  pos.y = (mob->pos).y;
  pos.z = (mob->pos).z + 1;
  blow_at(data->map, &pos, 2);
}

void	mob_loop(t_data *data)
{
  t_mob	*mob;
  int	x;

  mob = data->mob;
  x = 0;
  while (x < NB_MOB)
    {
      if (!(mob[x]).dead)
	{
	  ((mob[x]).pos).x -= (((mob[x]).pos).x - ((data->me).pos).x) / 100;
	  ((mob[x]).pos).y -= (((mob[x]).pos).y - ((data->me).pos).y) / 100;
	  mob_attack(data, &(mob[x]));
	}
      x += 1;
    }
}
