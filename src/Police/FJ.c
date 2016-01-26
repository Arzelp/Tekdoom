/*
** FJ.c for FJ in /home/arzel_p/rendu/sandbox/Lapinou/Police/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Jan 25 14:48:39 2016 Paskal Arzel
** Last update Tue Jan 26 14:49:44 2016 Paskal Arzel
*/

#include <stdlib.h>
#include "lapin.h"
#include "police.h"

int	letter_F(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "11111";
  tab[1] = "10000";
  tab[2] = "11110";
  tab[3] = "10000";
  tab[4] = "10000";
  godess(pix, list, tab);
  return (0);
}

int	letter_G(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "01111";
  tab[1] = "10000";
  tab[2] = "10111";
  tab[3] = "10001";
  tab[4] = "11111";
  godess(pix, list, tab);
  return (0);
}

int	letter_H(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "10001";
  tab[1] = "10001";
  tab[2] = "11111";
  tab[3] = "10001";
  tab[4] = "10001";
  godess(pix, list, tab);
  return (0);
}

int	letter_I(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "11111";
  tab[1] = "00100";
  tab[2] = "00100";
  tab[3] = "00100";
  tab[4] = "11111";
  godess(pix, list, tab);
  return (0);
}

int	letter_J(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "11111";
  tab[1] = "00001";
  tab[2] = "00001";
  tab[3] = "10001";
  tab[4] = "01110";
  godess(pix, list, tab);
  return (0);
}
