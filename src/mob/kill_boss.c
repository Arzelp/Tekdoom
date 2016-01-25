/*
** kill_boss.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jan 25 11:39:27 2016 Arthur Josso
** Last update Mon Jan 25 13:17:35 2016 Arthur Josso
*/

#include "doom.h"

void	hurt_boss(t_data *data)
{
  if (data->me.pointed_mob != -1)
    {
      data->mob[data->me.pointed_mob].tex = data->mob[0].tex_hurt;
    }
}

void	kill_boss(t_data *data)
{
  if (data->me.pointed_mob != -1)
    {
      data->mob[data->me.pointed_mob].tex = data->mob[0].tex_dead;
    }
}
