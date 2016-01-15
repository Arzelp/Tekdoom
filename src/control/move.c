/*
** move.c for move in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/gfx_tekdoom/src/control/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Jan 15 13:14:31 2016 Paskal Arzel
** Last update Fri Jan 15 19:23:04 2016 Arthur Josso
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "map.h"
#include "control.h"

int	walk_checkcoli(t_pos pos, t_data *data)
{
  t_block	*block;
  int	i;

  i = 0;
  while (i <= 2)
    {
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

int     walk(t_data *data, float speed)
{
  t_pos		pos;

  ((data->me).pos).x += cos((data->me).alpha) * speed;
  pos.x = (int)((data->me).pos).x;
  pos.y = (int)((data->me).pos).y;
  pos.z = (int)((data->me).pos).z;
  if (walk_checkcoli(pos, data) == 1)
    ((data->me).pos).x -= cos((data->me).alpha) * speed;
  ((data->me).pos).y += sin((data->me).alpha) * speed;
  pos.x = (int)((data->me).pos).x;
  pos.y = (int)((data->me).pos).y;
  if (walk_checkcoli(pos, data) == 1)
    ((data->me).pos).y -= sin((data->me).alpha) * speed;
  return (0);
}

int     walk_side(t_data *data, float speed)
{
  t_pos         pos;

  ((data->me).pos).x += cos((data->me).alpha + M_PI / 2) * speed;
  pos.x = (int)((data->me).pos).x;
  pos.y = (int)((data->me).pos).y;
  pos.z = (int)((data->me).pos).z;
  if (walk_checkcoli(pos, data) == 1)
    ((data->me).pos).x -= cos((data->me).alpha + M_PI / 2) * speed;
  ((data->me).pos).y += sin((data->me).alpha + M_PI / 2) * speed;
  pos.x = (int)((data->me).pos).x;
  pos.y = (int)((data->me).pos).y;
  if (walk_checkcoli(pos, data) == 1)
    ((data->me).pos).y -= sin((data->me).alpha + M_PI / 2) * speed;
  return (0);
}

int	gomove(t_data *data)
{
  if (data->keys[BKS_E])
    walk(data, 0.1);
  if (data->keys[BKS_D])
    walk(data, -0.1);
  if (data->keys[BKS_S])
    walk_side(data, 0.1);
  if (data->keys[BKS_F])
    walk_side(data, -0.1);
  if (data->keys[BKS_LEFT])
    (data->me).alpha += 0.05;
  if (data->keys[BKS_RIGHT])
    (data->me).alpha -= 0.05;
  if (data->keys[BKS_UP])
    (data->me).beta -= 0.05;
  if (data->keys[BKS_DOWN])
    (data->me).beta += 0.05;
  return (0);
}
