/*
** UY.c for UY.c in /home/arzel_p/rendu/sandbox/Lapinou/Police/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Jan 25 21:16:21 2016 Paskal Arzel
** Last update Tue Jan 26 14:50:03 2016 Paskal Arzel
*/

#include <stdlib.h>
#include "lapin.h"
#include "police.h"

int	letter_U(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "10001";
  tab[1] = "10001";
  tab[2] = "10001";
  tab[3] = "10001";
  tab[4] = "01110";
  godess(pix, list, tab);
  return (0);
}

int	letter_V(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "10001";
  tab[1] = "10001";
  tab[2] = "01010";
  tab[3] = "01010";
  tab[4] = "00100";
  godess(pix, list, tab);
  return (0);
}

int	letter_W(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "10001";
  tab[1] = "10001";
  tab[2] = "10001";
  tab[3] = "10101";
  tab[4] = "01010";
  godess(pix, list, tab);
  return (0);
}

int	letter_X(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "10001";
  tab[1] = "01010";
  tab[2] = "00100";
  tab[3] = "01010";
  tab[4] = "10001";
  godess(pix, list, tab);
  return (0);
}

int	letter_Y(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "10001";
  tab[1] = "01010";
  tab[2] = "00100";
  tab[3] = "00100";
  tab[4] = "00100";
  godess(pix, list, tab);
  return (0);
}
