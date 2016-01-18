/*
** jump.c for jump.c in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/gfx_tekdoom/src/control/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Jan 15 15:11:52 2016 Paskal Arzel
** Last update Mon Jan 18 21:23:05 2016 Paskal Arzel
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "map.h"
#include "control.h"

int	ctrl_jumpin(t_data *data)
{
  t_pos		pos;
  int	i;

  pos.x = (int)((data->me).pos).x;
  pos.y = (int)((data->me).pos).y;
  pos.z = (int)((data->me).pos).z;
  if ((i = ctrl_checkcoli(pos, data, 0)) == 0 && (data->me).fall == 0)
    (data->me).fall = (data->me).fall - 0.4;
  return (0);
}

int	ctrl_fallen(t_data *data)
{
  t_pos		pos;

  (data->me).fall += 0.05;
  ((data->me).pos).z -= (data->me).fall;
  pos.x = (int)((data->me).pos).x;
  pos.y = (int)((data->me).pos).y;
  pos.z = (int)((data->me).pos).z + 1;
  if (ctrl_checkcoli(pos, data, 0) == 1 && (data->me).fall < 0)
    {
      ((data->me).pos).z = pos.z - 0.05;
      (data->me).fall = 0.05;
      return (0);
    }
  pos.z = (int)((data->me).pos).z;
  if (ctrl_checkcoli(pos, data, 0) == 1 && (data->me).fall != -0.5)
    {
      ((data->me).pos).z = pos.z + 1;
      (data->me).fall = 0;
      (data->me).inair = 0;
    }
  return (0);
}

int	ctrl_gojump(t_data *data)
{
  if (data->keys[BKS_SPACE])
    ctrl_jumpin(data);
  ctrl_fallen(data);
  return (0);
}
