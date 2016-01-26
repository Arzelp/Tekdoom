/*
** kill_boss.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jan 25 11:39:27 2016 Arthur Josso
** Last update Tue Jan 26 09:54:20 2016 alies_a
*/

#include "doom.h"

void	hurt_boss(t_data *data)
{
  if (data->me.pointed_mob != -1
      && data->mob[data->me.pointed_mob].tex != data->mob[0].tex_dead)
    {
      data->mob[data->me.pointed_mob].tex = data->mob[0].tex_hurt;
    }
}

void	kill_boss(t_data *data)
{
  if (data->me.pointed_mob != -1)
    {
      data->mob[data->me.pointed_mob].tex = data->mob[0].tex_dead;
      data->mob[data->me.pointed_mob].dead = 1;
    }
}
