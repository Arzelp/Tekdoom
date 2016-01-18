/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Mon Jan 18 12:53:29 2016 Paskal Arzel
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
  if (data->keys != NULL && data->keys[BKS_LCONTROL])
    ((data->me).pos).z -= 0.6;
  display(data);
  if (data->keys != NULL && data->keys[BKS_LCONTROL])
    ((data->me).pos).z += 0.6;
  drawjauge(data, data->pix);
  bunny_blit(&((data->win)->buffer), &((data->pix)->clipable), &zero);
  //bunny_blit(&((data->win)->buffer), &((data->texture)->clipable), &zero);
  bunny_display(data->win);
  return (GO_ON);
}

/* Trololol, c'est juste pour tester cette fonction avec beaucoup de param */
void		create_carre(t_map *map, int large, int lx, int ly, int z, int texture)
{
  t_block x;
  t_pos pos;

  x.x = 1;
  x.texture = texture;
  pos.z = z;
  pos.x = lx;
  while (pos.x <= lx + large)
    {
      pos.y = ly;
      while (pos.y <= ly + large)
	{
	  if ((pos.x == lx || pos.x == lx + large) ||
	      (pos.y == ly || pos.y == ly + large))
	    map_set(map, &pos, x);
	  pos.y++;
	}
      pos.x++;
    }
}

t_map		*init_map()
{
  t_map *map;
  t_block x;
  t_pos pos;

  x.x = 1;
  x.texture = 4;
  if ((map = map_gen(50)) == NULL)
    return (NULL);
  map_set_flat(map);
  map_set_wall(map);

  pos.x = 6;
  pos.y = 1;
  pos.z = 1;
  while (pos.y <= 9)
    {
      map_set(map, &pos, x);
      pos.z++;
      pos.y++;
    }

  create_carre(map, 1, 15, 15, 1, 9);
  create_carre(map, 2, 14, 14, 2, 1);
  create_carre(map, 4, 13, 13, 3, 2);
  create_carre(map, 6, 12, 12, 4, 3);
  create_carre(map, 8, 11, 11, 5, 4);
  create_carre(map, 10, 10, 10, 4, 5);
  create_carre(map, 12, 9, 9, 3, 6);
  create_carre(map, 14, 8, 8, 2, 7);
  create_carre(map, 16, 7, 7, 1, 8);

  //map_print(map);
  return (map);
}

void		init_player(t_me *player)
{
  (player->pos).x = 2.5;
  (player->pos).y = 2.5;
  (player->pos).z = 3;
  player->alpha = 0.5;
  player->beta = 0;
  player->fall = 0;
  player->inair = 0;
  player->sprint = 60;
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
  if ((data.texture = load_bitmap("res/textures.bmp")) == NULL)
    return (1);
  //(data.texture)->pixels += 32;
  if ((data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if ((data.win = bunny_start(WIDTH, HEIGHT, false, "TekDoom")) == NULL)
    return (1);
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(&key_listenner);
  bunny_loop(data.win, FPS, (void*)(&data));
  bunny_stop(data.win);
  bunny_delete_clipable(&((data.pix)->clipable));
  return (0);
}
