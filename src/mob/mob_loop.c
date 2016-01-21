/*
** mob_loop.c for mob loop in /home/alies_a/rendu/gfx_tekdoom
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan 21 17:57:17 2016 alies_a
** Last update Thu Jan 21 17:59:09 2016 alies_a
*/

#include "doom.h"

void	mob_loop(t_data *data)
{
  ((data->mob)->pos).x -= (((data->mob)->pos).x - ((data->me).pos).x) / 100;
  ((data->mob)->pos).y -= (((data->mob)->pos).y - ((data->me).pos).y) / 100;
}
