/*
** control.c for controll in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/src/control/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Jan 15 11:37:21 2016 Paskal Arzel
** Last update Sat Jan 16 12:16:17 2016 Paskal Arzel
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "map.h"
#include "control.h"

int	initjump(t_data	*data)
{
  t_jump	*jump;

  if ((jump = malloc(sizeof(t_jump))) == NULL)
    return (1);
  jump->fall = 0;
  jump->inair = 0;
  data->jump = jump;
  return (0);
}

int     move(t_data *data)
{
  if (data->jump == NULL)
    initjump(data);
  if (data->keys != NULL)
    {
      gomove(data);
      gojump(data);
      /*if (data->keys[BKS_P])
	p = !p;*/
      if (data->keys[BKS_B])
	map_create_block(data, data->map, (data->me).pos);
    }
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
