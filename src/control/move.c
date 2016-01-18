/*
** move.c for move in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/gfx_tekdoom/src/control/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Jan 15 13:14:31 2016 Paskal Arzel
** Last update Mon Jan 18 21:25:28 2016 Paskal Arzel
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "map.h"
#include "control.h"

int	ctrl_checkcoli(t_pos pos, t_data *data, int size)
{
  t_block	*block;
  int	i;

  i = size;
  pos.z = pos.z - i;
  while (i < 3)
    {
      if (pos.z <= 0)
	return (1);
      block = map_get(data->map, &pos);
      if (block == NULL)
	return (1);
      if (block->x != 0)
	return (1);
      pos.z--;
      i++;
    }
  return (0);
}

int     ctrl_walk(t_data *data, float speed, int size)
{
  t_pos		pos;

  ((data->me).pos).x += cos((data->me).alpha) * speed;
  pos.x = (int)((data->me).pos).x;
  pos.y = (int)((data->me).pos).y;
  pos.z = (int)((data->me).pos).z;
  if ((data->keys[BKS_LSHIFT]) && (data->me).sprint < 0)
    (data->me).sprint = -10;
  if (ctrl_checkcoli(pos, data, size) == 1)
    ((data->me).pos).x -= cos((data->me).alpha) * speed;
  ((data->me).pos).y += sin((data->me).alpha) * speed;
  pos.x = (int)((data->me).pos).x;
  pos.y = (int)((data->me).pos).y;
  if (ctrl_checkcoli(pos, data, size) == 1)
    ((data->me).pos).y -= sin((data->me).alpha) * speed;
  return (0);
}

int     ctrl_walkside(t_data *data, float speed, int size)
{
  t_pos         pos;

  ((data->me).pos).x += cos((data->me).alpha + M_PI / 2) * speed;
  pos.x = (int)((data->me).pos).x;
  pos.y = (int)((data->me).pos).y;
  pos.z = (int)((data->me).pos).z;
  if (ctrl_checkcoli(pos, data, size) == 1)
    ((data->me).pos).x -= cos((data->me).alpha + M_PI / 2) * speed;
  ((data->me).pos).y += sin((data->me).alpha + M_PI / 2) * speed;
  pos.x = (int)((data->me).pos).x;
  pos.y = (int)((data->me).pos).y;
  if (ctrl_checkcoli(pos, data, size) == 1)
    ((data->me).pos).y -= sin((data->me).alpha + M_PI / 2) * speed;
  return (0);
}

int	ctrl_camera(t_data *data)
{
  if (data->keys[BKS_LEFT])
    (data->me).alpha += 0.07;
  if (data->keys[BKS_RIGHT])
    (data->me).alpha -= 0.07;
  if (data->keys[BKS_UP])
    (data->me).beta -= 0.07;
  if (data->keys[BKS_DOWN])
    (data->me).beta += 0.07;
  return (0);
}

int	ctrl_gomove(t_data *data)
{
  int	size;

  size = (data->keys[BKS_LCONTROL]) ? 1 : 0;
  if (data->keys[BKS_E])
    {
      if (data->keys[BKS_LSHIFT] && data->me.sprint > 0)
	ctrl_walk(data, 0.25, 0);
      else
	ctrl_walk(data, 0.1, size);
      data->me.sprint -= (data->keys[BKS_LSHIFT] &&
		       data->me.sprint > 0) ? 0.55 : 0;
    }
  if (data->keys[BKS_D])
    ctrl_walk(data, -0.1, size);
  if (data->keys[BKS_S])
    ctrl_walkside(data, 0.1, size);
  if (data->keys[BKS_F])
    ctrl_walkside(data, -0.1, size);
  ctrl_camera(data);
  return (0);
}
