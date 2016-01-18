/*
** fly.c for fly in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/gfx_tekdoom/gfx_tekdoom/src/control/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Jan 18 22:21:41 2016 Paskal Arzel
** Last update Mon Jan 18 22:42:55 2016 Paskal Arzel
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "control.h"

int	ctrl_flymove(t_data *data, float speed)
{
  t_pos	pos;

  ((data->me).pos).z += speed;
  pos.x = (int)((data->me).pos).x;
  pos.y = (int)((data->me).pos).y;
  pos.z = (int)((data->me).pos).z;
  if (ctrl_checkcoli(pos, data, 0) == 1)
    ((data->me).pos).z -= speed;
  return (0);
}

int	ctrl_fly(t_data *data)
{
  if (data->keys[BKS_O])
    data->me.fly = 1;
  if (data->keys[BKS_L])
    data->me.fly = 0;
  if (data->me.fly == 1)
    {
      data->me.sprint = SPRMAX;
      if (data->keys[BKS_P])
	ctrl_flymove(data, 0.1);
      if (data->keys[BKS_M])
	ctrl_flymove(data, -0.1);
    }
  return (0);
}
