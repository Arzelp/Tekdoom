/*
** jump.c for jump.c in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/gfx_tekdoom/src/control/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Jan 15 15:11:52 2016 Paskal Arzel
** Last update Fri Jan 15 19:48:31 2016 Paskal Arzel
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "map.h"
#include "control.h"

void	my_put_nbr(int a)
{
  int	f;
  int	b;

  b = a;
  f = 1;
  if (a == 0)
    my_putchar(48);
  if (a < 0)
    {
      my_putchar('-');
      my_put_nbr(-a);
    }
  while (b >= 10)
    {
      b = b / 10;
      f = f * 10;
    }
  while (f >= 1)
    {
      my_putchar(a / f + 48);
      a = a % f;
      f = f / 10;
    }
}

int	jumpin(t_data *data)
{
  t_pos		pos;
  int	i;

  pos.x = (int)((data->me).pos).x;
  pos.y = (int)((data->me).pos).y;
  pos.z = (int)((data->me).pos).z;
  if ((i = walk_checkcoli(pos, data)) == 0 && (data->jump)->fall == 0)
    (data->jump)->fall = (data->jump)->fall - 0.4;
  return (0);
}

int	fallen(t_data *data)
{
  t_pos		pos;

  (data->jump)->fall += 0.05;
  ((data->me).pos).z -= (data->jump)->fall;
  pos.x = (int)((data->me).pos).x;
  pos.y = (int)((data->me).pos).y;
  pos.z = (int)((data->me).pos).z;
  if (walk_checkcoli(pos, data) == 1 && (data->jump)->fall != -0.5)
    {
      ((data->me).pos).z = pos.z + 1;
      (data->jump)->fall = 0;
      (data->jump)->inair = 0;
    }
  return (0);
}

int	gojump(t_data *data)
{
  if (data->keys[BKS_SPACE])
    jumpin(data);
  fallen(data);
  return (0);
}
