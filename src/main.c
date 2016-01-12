/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Tue Jan 12 17:52:11 2016 Arnaud Alies
*/

#include <lapin.h>
#include "doom.h"

static t_bunny_response	loop(void *data_pt)
{
  t_data		*data;
  t_bunny_position      zero;

  zero.x = 0;
  zero.y = 0;
  data = (t_data*)data_pt;
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

int		main(int ac, char **av)
{
  t_data	data;

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
