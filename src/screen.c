/*
** screen.c for screen in /home/arzel_p/rendu/gfx_tekdoom/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Wed Jan 13 14:53:48 2016 Paskal Arzel
** Last update Wed Jan 13 15:20:58 2016 Paskal Arzel
*/

#include <math.h>
#include "doom.h"
#include "my.h"

t_vec	*screenpos(t_vec *ppos, float alpha, float beta, int pos)
{
  t_vec	*scr;
  int	posx;
  int	posy;

  posx = pos % WIDTH;
  posy = pos / WIDTH;
  scr->x = 0.5 * cos(alpha) * cos(beta) + ppos->x;
  scr->y = (((WIDTH / 2) - posx) / WIDTH) * cos(alpha) * sin(beta) + ppos->y;
  scr->z = (((HEIGHT / 2) - posy) / HEIGHT) * sin(alpha) + ppos->z;
  return (src);
}
