/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
<<<<<<< HEAD
** Last update Fri Jan 15 14:55:26 2016 Arnaud Alies
=======
** Last update Fri Jan 15 13:22:08 2016 Arnaud Alies
>>>>>>> 5fd7d8f2e3d33ea5fe290e8f2be5fe3a957e8163
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "map.h"
#include "control.h"

static t_bunny_response	loop(void *data_pt)
{
  t_data		*data;
  t_bunny_position      zero;

  zero.x = 0;
  zero.y = 0;
  data = (t_data*)data_pt;
  move(data);
  /*printf("%f %f %f | %f\n",
	 ((data->me).pos).x,
	 ((data->me).pos).y,
	 ((data->me).pos).z,
	 (data->me).alpha);*/
  display(data);
  bunny_blit(&((data->win)->buffer), &((data->pix)->clipable), &zero);
  bunny_display(data->win);
  return (GO_ON);
}

t_map		*init_map()
{
  t_map *map;
  t_block x;
  t_pos pos;

  x.x = 1;
  if ((map = map_gen(8)) == NULL)
    return (NULL);
  map_set_flat(map);
  map_set_wall(map);

  pos.x = 6;
  pos.y = 6;
  pos.z = 4;
  map_set(map, &pos, x);
  pos.x = 6;
  pos.y = 5;
  pos.z = 3;
  map_set(map, &pos, x);
  pos.x = 6;
  pos.y = 4;
  pos.z = 2;
  map_set(map, &pos, x);
  pos.x = 6;
  pos.y = 3;
  pos.z = 1;
  map_set(map, &pos, x);
  map_print(map);
  return (map);
}

void		init_player(t_me *player)
{
  (player->pos).x = 2.5;
  (player->pos).y = 2.5;
  (player->pos).z = 3;
  player->alpha = 0.5;
  player->beta = 0;
}

int		main(int ac, char **av)
{
  t_data	data;

  (void)ac;
  (void)av;
  data.keys = NULL;
  if ((data.map = init_map()) == NULL)
    return (1);
  init_player(&(data.me));
  if ((data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if ((data.win = bunny_start(WIDTH, HEIGHT, false, "Pute")) == NULL)
    return (1);
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(&key_listenner);
  bunny_loop(data.win, FPS, (void*)(&data));
  bunny_stop(data.win);
  bunny_delete_clipable(&((data.pix)->clipable));
  return (0);
}
