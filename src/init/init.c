/*
** init.c for tekdoom in /home/josso/rendu/gfx/gfx_tekdoom
**
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
**
** Started on  Tue Jan 19 11:25:43 2016 Arthur Josso
** Last update Wed Jan 20 17:12:05 2016 alies_a
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
      map_set_flat(map);
      map_set_wall(map);
    }
  return (map);
}

void	init_player(t_me *player)
{
  (player->pos).x = 2.5;
  (player->pos).y = 2.5;
  (player->pos).z = 3;
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
  if ((data->mob = malloc(1 * sizeof(t_mob))) == NULL)
    return (1);
  if ((data->mob[0].tex = load_bitmap("res/boss.bmp")) == NULL)
    return (1);
  data->mob[0].pos.x = 10;
  data->mob[0].pos.y = 10;
  data->mob[0].pos.z = 0;
  return (0);
}

int	init_all(t_data *data, int ac, char **av)
{
  (data->select).selected = 0;
  (data->select).open = 0;
  if ((data->texture = load_bitmap("res/textures.bmp")) == NULL)
    return (1);
  if ((data->map = init_map(ac, av)) == NULL)
    return (1);
  init_player(&(data->me));
  if (init_mob(data) == 1)
    return (1);
  return (0);
}
