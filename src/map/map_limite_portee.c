/*
** map_limite_portee.c for limite de portée in /src/map/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Jan 26 18:47:05 2016 Frederic ODDOU
** Last update Tue Jan 26 18:47:05 2016 Frederic ODDOU
*/

#include "doom.h"

int		my_abs(int a, int b)
{
  int		c;

  c = a - b;
  if (c < 0)
    c *= -1;
  return (c);
}

int		map_limite_portee(t_data *data, t_hit hit)
{
  if (my_abs((hit.blk).x, (data->me.pos).x) <= 7 &&
      my_abs((hit.blk).y, (data->me.pos).y) <= 7 &&
      my_abs((hit.blk).z, (data->me.pos).z) <= 7)
    return (0);
  else
    return (1);
}
