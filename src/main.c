/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Fri Jan 15 18:58:23 2016 Arnaud Alies
*/

#include <lapin.h>
#include <math.h>
#include "bmp.h"
#include "doom.h"
#include "map.h"
#include "control.h"


t_color		get_texture(t_data *data,
			    t_pos *block_x,
			    t_bunny_position *pos)
{
  t_bunny_pixelarray	*text;
  t_block		*block;
  t_color		res;

  res.full = WHITE;
  if ((block = map_get(data->map, block_x)) == NULL)
    return (res);
  text = data->texture;
  pos->x += block->texture * 32;
  res = get_pixel(text, pos);
  return (res);
}

static t_bunny_response	loop(void *data_pt)
{
  t_data		*data;
  t_bunny_position      zero;

  zero.x = 0;
  zero.y = 0;
  data = (t_data*)data_pt;
  move(data);
  display(data);
  bunny_blit(&((data->win)->buffer), &((data->pix)->clipable), &zero);
  //bunny_blit(&((data->win)->buffer), &((data->texture)->clipable), &zero);
  bunny_display(data->win);
  return (GO_ON);
}

t_map		*init_map()
{
  t_map *map;
  t_block x;
  t_pos pos;

  x.x = 1;
  x.texture = 4;
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

/*void	init_jump(t_jump *jump)
{
  jump->fall = 0;
  jump->inair = 0;
  jump->impuls = 0;
}*/

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
/*  init_jump(&(data.jump));*/
  if ((data.texture = load_bitmap("res/textures.bmp")) == NULL)
    return (1);
  //(data.texture)->pixels += 32;
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
