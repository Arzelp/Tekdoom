/*
** screen.c for screen in /home/arzel_p/rendu/gfx_tekdoom/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Wed Jan 13 14:53:48 2016 Paskal Arzel
** Last update Wed Jan 13 18:26:49 2016 Paskal Arzel
*/

#include <math.h>
#include "doom.h"
#include "calc.h"

static t_ray	*calc_ray(t_vec *ppos, t_vec *scr)
{
  t_ray	*ray;

  if ((ray = malloc(sizeof(t_ray))) == NULL)
    return (NULL);
  (ray->alpha).x = ppos->x;
  (ray->alpha).y = ppos->y;
  (ray->alpha).z = ppos->z;
  (ray->beta).x = 2 * (scr->x - ppos->x);
  (ray->beta).y = 2 * (scr->y - ppos->y);
  (ray->beta).z = 2 * (scr->z - ppos->z);
  return (ray);
}

t_ray	*calc_screenpos(t_vec *ppos, float alpha, float beta, int pos)
{
  t_vec	*scr;
  t_ray	*ray;
  float	posx;
  float	posy;

  if ((scr = malloc(sizeof(t_vec))) == NULL
      || (ray = malloc(sizeof(t_ray))) == NULL)
    return (NULL);
  posx = pos % WIDTH;
  posy = pos / WIDTH;
  scr->x = 0.5 * cos(beta) * cos(alpha) + ppos->x;
  scr->y = (((WIDTH / 2) - posx) / WIDTH) * cos(beta) * sin(alpha) + ppos->y;
  scr->z = (((HEIGHT / 2) - posy) / HEIGHT) * sin(beta) + ppos->z;
  if ((ray = calc_ray(ppos, scr)) == NULL)
    return (NULL);
  return (ray);
}
