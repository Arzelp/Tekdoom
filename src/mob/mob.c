/*
** mob.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 19 10:17:50 2016 Arthur Josso
** Last update Thu Jan 21 19:20:27 2016 Arthur Josso
*/

#include "doom.h"

void	test_mobs(t_data *data, t_ray *ray, t_hit *hit)
{
  int	i;

  i = 0;
  while (i < NB_MOB)
    {
      test_mob(data, ray, hit, i);
      i++;
    }
}
