/*
** control.c for controll in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/src/control/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Jan 15 11:37:21 2016 Paskal Arzel
** Last update Tue Jan 19 11:44:36 2016 Arthur Josso
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
      if (data->me.fly == 0)
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
