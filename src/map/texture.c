/*
** texture.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 19 11:40:27 2016 Arthur Josso
** Last update Tue Jan 19 11:40:47 2016 Arthur Josso
*/

#include "doom.h"

t_color                 get_texture(t_data *data,
				    t_pos *block_x,
				    t_bunny_position *pos)
{
  t_bunny_pixelarray    *text;
  t_block               *block;
  t_color               res;

  res.full = WHITE;
  if ((block = map_get(data->map, block_x)) == NULL)
    return (res);
  text = data->texture;
  pos->y = 31 - pos->y;
  pos->x += (block->texture % 16) * 32;
  pos->y += (block->texture / 16) * 32;
  res = get_pixel(text, pos);
  return (res);
}
