/*
** init.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
**
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
**
** Started on  Tue Jan 19 11:25:43 2016 Arthur Josso
** Last update Tue Jan 26 21:10:34 2016 Paskal Arzel
*/

#include <stdlib.h>
#include "doom.h"
#include "control.h"
#include "bmp.h"

t_map	*init_map(int ac, char **av)
{
  t_map *map;

  if (ac >= 2)
    {
      if ((map = load_map(av[1])) == NULL)
	return (NULL);
    }
  else
    {
      if ((map = map_gen(50)) == NULL)
	return (NULL);
      map_set_wall(map);
    }
  return (map);
}

void	init_player(t_me *player)
{
  (player->pos).x = 2.5;
  (player->pos).y = 2.5;
  (player->pos).z = 21;
  player->alpha = 0.5;
  player->beta = 0;
  player->fall = 0;
  player->inair = 0;
  player->sprint = SPRMAX;
  player->fly = 0;
  player->speedfront = 0;
  player->speedside = 0;
}

int	init_gun(t_gun *gun)
{
  if ((gun->tex = load_bitmap("res/gun.bmp")) == NULL)
    return (1);
  if ((gun->sound = bunny_load_effect("res/pan.ogg")) == NULL)
    return (1);
  bunny_sound_volume(gun->sound, 100);
  gun->beg.x = (2 * WIDTH) / 5;
  gun->end.x = (4 * WIDTH) / 5;
  gun->beg.y =  HEIGHT / 3 + 10;
  gun->end.y = HEIGHT;
  gun->size.x = 155;
  gun->size.y = 110;
  gun->frame_pos.x = 0;
  gun->frame_pos.y = 0;
  gun->fire = 0;
  gun->speed = 0.4;
  return (0);
}

int	init_all(t_data *data, int ac, char **av)
{
  (data->select).selected = 0;
  (data->select).open = 0;
  data->end = -1;
  if ((data->end_pix = load_bitmap("res/end.bmp")) == NULL)
    return (1);
  if ((data->texture = load_bitmap("res/textures.bmp")) == NULL)
    return (1);
  if ((data->sound.boom = bunny_load_effect("res/boom.ogg")) == NULL)
    return (1);
  bunny_sound_volume(data->sound.boom, 100);
  if ((data->map = init_map(ac, av)) == NULL)
    return (1);
  init_player(&(data->me));
  if (init_mob(data) == 1)
    return (1);
  if (init_gun(&data->gun) == 1)
    return (1);
  return (0);
}
