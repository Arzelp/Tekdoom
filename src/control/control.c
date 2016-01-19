/*
** control.c for controll in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/src/control/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Jan 15 11:37:21 2016 Paskal Arzel
** Last update Tue Jan 19 16:08:22 2016 Paskal Arzel
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "control.h"

int	ctrl_inertie(t_data *data)
{
  if ((data->me).speedfront < 0)
    {
      (data->me).speedfront += INER;
      if ((data->me).speedfront > 0)
	(data->me).speedfront = 0;
    }
  if ((data->me).speedfront > 0)
    {
      (data->me).speedfront -= INER;
      if ((data->me).speedfront < 0)
	(data->me).speedfront = 0;
    }
  if ((data->me).speedside < 0)
    {
      (data->me).speedside += INER;
      if ((data->me).speedside > 0)
	(data->me).speedside = 0;
        }
  if ((data->me).speedside > 0)
    {
      (data->me).speedside -= INER;
      if ((data->me).speedside < 0)
	(data->me).speedside = 0;
    }
  return (0);
}

int	ctrl_speed(t_data *data)
{
  if (data->keys[BKS_E])
    (data->me).speedfront += ((data->me).speedfront > VITMAX - ACC) ? 0 : ACC;
  if (data->keys[BKS_D])
    (data->me).speedfront -= ((data->me).speedfront < -VITMAX + ACC) ? 0 : ACC;
  if (data->keys[BKS_S])
    (data->me).speedside += ((data->me).speedside > VITMAX - ACC) ? 0 : ACC;
  if (data->keys[BKS_F])
    (data->me).speedside -= ((data->me).speedside < -VITMAX + ACC) ? 0 : ACC;
}

int     ctrl_move(t_data *data)
{
  (data->me).crowd = 0;
  if (data->keys != NULL)
    {
      ctrl_speed(data);
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
  ctrl_inertie(data);
  return (0);
}
