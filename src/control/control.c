/*
** control.c for controll in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/src/control/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Jan 15 11:37:21 2016 Paskal Arzel
** Last update Mon Jan 18 21:28:19 2016 Paskal Arzel
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "control.h"

int     ctrl_move(t_data *data)
{
  (data->me).crowd = 0;
  if (data->keys != NULL)
    {
      ctrl_gomove(data);
      ctrl_gojump(data);
      if (data->keys[BKS_C])
	map_create_block(data);
      if (data->keys[BKS_V])
	map_delete_block(data);
      if (data->keys[BKS_LCONTROL])
	(data->me).crowd = 0.6;
    }
  if ((data->me).sprint + REGENSPR <= SPRMAX)
    (data->me).sprint += REGENSPR;
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
