/*
** AE.c for AE in /home/arzel_p/rendu/sandbox/Lapinou/Police/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Jan 25 14:48:35 2016 Paskal Arzel
** Last update Tue Jan 26 17:21:27 2016 alies_a
*/

#include <stdlib.h>
#include "lapin.h"
#include "police.h"

int	letter_A(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "01110";
  tab[1] = "10001";
  tab[2] = "11111";
  tab[3] = "10001";
  tab[4] = "10001";
  godess(pix, list, tab);
  return (0);
}

int	letter_B(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "11110";
  tab[1] = "10001";
  tab[2] = "11110";
  tab[3] = "10001";
  tab[4] = "11110";
  godess(pix, list, tab);
  return (0);
}

int	letter_C(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "01110";
  tab[1] = "10001";
  tab[2] = "10000";
  tab[3] = "10001";
  tab[4] = "01110";
  godess(pix, list, tab);
  return (0);
}

int	letter_D(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "11110";
  tab[1] = "10001";
  tab[2] = "10001";
  tab[3] = "10001";
  tab[4] = "11110";
  godess(pix, list, tab);
  return (0);
}

int	letter_E(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "11111";
  tab[1] = "10000";
  tab[2] = "11110";
  tab[3] = "10000";
  tab[4] = "11111";
  godess(pix, list, tab);
  return (0);
}
