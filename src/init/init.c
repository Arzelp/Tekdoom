/*
** init.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
**
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
**
** Started on  Tue Jan 19 11:25:43 2016 Arthur Josso
** Last update Tue Jan 26 09:51:56 2016 alies_a
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
  (player->pos).z = 20;
  player->alpha = 0.5;
  player->beta = 0;
  player->fall = 0;
  player->inair = 0;
  player->sprint = SPRMAX;
  player->fly = 0;
  player->speedfront = 0;
  player->speedside = 0;
}

int	init_mob(t_data *data)
{
  if ((data->mob = bunny_malloc(sizeof(t_mob) * NB_MOB)) == NULL)
    return (1);
  if ((data->mob[0].tex_alive = load_bitmap("res/boss_alive.bmp")) == NULL)
    return (1);
  if ((data->mob[0].tex_hurt = load_bitmap("res/boss_hurt.bmp")) == NULL)
    return (1);
  if ((data->mob[0].tex_dead = load_bitmap("res/boss_dead.bmp")) == NULL)
    return (1);
  data->mob[0].tex = data->mob[0].tex_alive;
  data->mob[0].pos.x = 10.5;
  data->mob[0].pos.y = 10.5;
  data->mob[0].pos.z = 1;
  data->mob[0].size.x = 2;
  data->mob[0].size.y = 5;
  data->mob[0].dead = 0;
  data->mob[1].tex = data->mob[0].tex_alive;
  data->mob[1].pos.x = 10.5;
  data->mob[1].pos.y = 10.5;
  data->mob[1].pos.z = 1;
  data->mob[1].size.x = 2;
  data->mob[1].size.y = 5;
  data->mob[1].dead = 0;
  data->mob[2].tex = data->mob[0].tex_alive;
  data->mob[2].pos.x = 12.5;
  data->mob[2].pos.y = 12.5;
  data->mob[2].pos.z = 1;
  data->mob[2].size.x = 2;
  data->mob[2].size.y = 5;
  data->mob[2].dead = 0;
  return (0);
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
  gun->beg.y =  HEIGHT / 2;
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
