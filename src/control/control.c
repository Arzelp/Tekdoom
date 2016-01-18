/*
** control.c for controll in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/src/control/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Jan 15 11:37:21 2016 Paskal Arzel
** Last update Mon Jan 18 17:30:09 2016 alies_a
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "control.h"

int     move(t_data *data)
{
  if (data->keys != NULL)
    {
      gomove(data);
      gojump(data);
      if (data->keys[BKS_C])
	map_create_block(data);
      if (data->keys[BKS_V])
	map_delete_block(data);
    }
  if ((data->me).sprint < 99.8)
    (data->me).sprint += 0.15;
  return (0);
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
