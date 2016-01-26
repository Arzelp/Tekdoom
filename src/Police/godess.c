/*
** godess.c for godess in /home/arzel_p/rendu/sandbox/Lapinou/Police/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Jan 25 18:48:28 2016 Paskal Arzel
** Last update Tue Jan 26 15:21:52 2016 Paskal Arzel
*/

#include <stdlib.h>
#include "lapin.h"
#include "police.h"

int	gocarre(t_bunny_pixelarray *pix, t_pol *list)
{
  int	i;
  int	j;

  j = -1;
  while (++j < list->size)
    {
      i = -1;
      while (++i < list->size)
	{
	  tekpixel(pix, list->pos, list->color);
	  list->pos->x += 1;
	}
      list->pos->x -= list->size;
      list->pos->y += 1;
    }
  list->pos->y -= list->size;
  return (0);
}

int	godess(t_bunny_pixelarray *pix, t_pol *list, char **tab)
{
  int	i;
  int	j;

  j = -1;
  while (++j < 5)
    {
      i = -1;
      while (++i < 5)
	{
	  if (tab[j][i] == '1')
	    gocarre(pix, list);
	  list->pos->x += list->size;
	}
      list->pos->x -= 5 * list->size;
      list->pos->y += list->size;
    }
  list->pos->y -= 5 * list->size;
  return (0);
}
