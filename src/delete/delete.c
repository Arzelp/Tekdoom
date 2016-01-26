/*
** delete.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Jan 24 12:29:05 2016 Arthur Josso
** Last update Mon Jan 25 11:36:44 2016 Arthur Josso
*/

#include "doom.h"

static void	sound(t_data *data)
{
  bunny_delete_sound(data->gun.sound);
  bunny_delete_sound(data->sound.boom);
}

static void	pixel_array(t_data *data)
{
  bunny_delete_clipable(&data->mob[0].tex_alive->clipable);
  bunny_delete_clipable(&data->mob[0].tex_hurt->clipable);
  bunny_delete_clipable(&data->mob[0].tex_dead->clipable);
  bunny_delete_clipable(&data->pix->clipable);
  bunny_delete_clipable(&data->texture->clipable);
  bunny_delete_clipable(&data->gun.tex->clipable);
}

void	delete_all(t_data *data)
{
  sound(data);
  pixel_array(data);
  bunny_stop(data->win);
}
