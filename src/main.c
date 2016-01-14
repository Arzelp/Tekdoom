/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Thu Jan 14 10:52:38 2016 Arnaud Alies
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "map.h"

int     walk(t_data *data, int speed)
{
  ((data->me).pos).x += cos((data->me).alpha) / 100 * speed;
  ((data->me).pos).y += sin((data->me).alpha) / 100 * speed;
  return (0);
}

int     move(t_data *data)
{
  if (data->keys != NULL)
    {
      if (data->keys[BKS_D])
	(data->me).alpha -= 0.05;
      if (data->keys[BKS_Q])
	(data->me).alpha += 0.05;
      if (data->keys[BKS_Z])
	walk(data, 1);
      if (data->keys[BKS_S])
	walk(data, -1);
    }
  return (0);
}

static t_bunny_response	loop(void *data_pt)
{
  t_data		*data;
  t_bunny_position      zero;

  zero.x = 0;
  zero.y = 0;
  data = (t_data*)data_pt;
  move(data);
  printf("%f\n", (data->me).alpha);
  display(data);
  bunny_blit(&((data->win)->buffer), &((data->pix)->clipable), &zero);
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response key_listenner(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *data_pt)
{
  t_data	*data;

  data = (t_data*)data_pt;
  data->keys = bunny_get_keyboard();
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_map		*init_map()
{
  t_map *map;
  
  if ((map = map_gen(5)) == NULL)
    return (NULL);
  map_set_flat(map);
  map_set_wall(map);
  map_print(map);
  return (map);
}

void		init_player(t_me *player)
{
  (player->pos).x = 2;
  (player->pos).y = 2;
  (player->pos).z = 2;
  player->alpha = 0;
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
