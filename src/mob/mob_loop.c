/*
** mob_loop.c for mob loop in /home/alies_a/rendu/gfx_tekdoom
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan 21 17:57:17 2016 alies_a
** Last update Tue Jan 26 09:38:28 2016 alies_a
*/

#include "doom.h"

void	mob_loop(t_data *data)
{
  t_mob	*mob;
  int	x;

  mob = data->mob;
  x = 0;
  while (x < NB_MOB)
    {
      ((mob[x]).pos).x -= (((mob[x]).pos).x - ((data->me).pos).x) / 100;
      ((mob[x]).pos).y -= (((mob[x]).pos).y - ((data->me).pos).y) / 100;
      x += 1;
    }
}
