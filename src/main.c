/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Thu Jan 21 19:29:35 2016 alies_a
*/

#include <lapin.h>
#include <math.h>
#include "bmp.h"
#include "doom.h"
#include "control.h"
#include "my.h"

void	set_select(t_select *select, int add)
{
  int	buf;

  buf = select->selected + add;
  if (buf >= 0 && buf < MAX_TEXT)
    select->selected += add;
}

t_bunny_response key_listenner(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *data_pt)
{
  t_data        *data;

  data = (t_data*)data_pt;
  data->keys = bunny_get_keyboard();
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (state == GO_DOWN && keysym == BKS_C)
    map_create_block(data);
  if (state == GO_DOWN && keysym == BKS_X)
    map_delete_block(data);
  if ((data->select).open && state == GO_DOWN)
    {
      if (keysym == BKS_RIGHT)
	set_select(&(data->select), 1);
      if (keysym == BKS_LEFT)
	set_select(&(data->select), -1);
      if (keysym == BKS_UP)
	set_select(&(data->select), -16);
      if (keysym == BKS_DOWN)
	set_select(&(data->select), 16);
    }
  return (GO_ON);
}

static t_bunny_response	loop(void *data_pt)
{
  t_data		*data;
  t_bunny_position      zero;

  zero.x = 0;
  zero.y = 0;
  data = (t_data*)data_pt;
  display(data);
  mob_loop(data);
  ctrl_drawjauge(data, data->pix);
  bunny_blit(&((data->win)->buffer), &((data->pix)->clipable), &zero);
  ctrl_move(data);
  bunny_display(data->win);
  return (GO_ON);
}

int		main(int ac, char **av)
{
  t_data	data;

  (void)ac;
  (void)av;
  data.keys = NULL;
  if (init_all(&data, ac, av) == 1)
    return (1);
  if ((data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if ((data.win = bunny_start(WIDTH, HEIGHT, false, "TekDoom")) == NULL)
    return (1);
  t_pos pos;

  pos.x = 15;
  pos.y = 15;
  pos.z = 10;
  blow_at(data.map, &pos, 15);
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(&key_listenner);
  bunny_loop(data.win, FPS, (void*)(&data));
  bunny_delete_clipable(&((data.pix)->clipable));
  bunny_stop(data.win);
  if (map_save(data.map, "autosave.josso"))
    {
      my_putstr("Error while saving\n");
      return (1);
    }
  return (0);
}
