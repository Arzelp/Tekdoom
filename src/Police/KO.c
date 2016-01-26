/*
** KO.c for KO in /home/arzel_p/rendu/sandbox/Lapinou/Police/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Jan 25 14:48:42 2016 Paskal Arzel
** Last update Tue Jan 26 14:49:50 2016 Paskal Arzel
*/

#include <stdlib.h>
#include "lapin.h"
#include "police.h"

int	letter_K(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "10001";
  tab[1] = "10110";
  tab[2] = "11000";
  tab[3] = "10110";
  tab[4] = "10001";
  godess(pix, list, tab);
  return (0);
}

int	letter_L(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "10000";
  tab[1] = "10000";
  tab[2] = "10000";
  tab[3] = "10000";
  tab[4] = "11111";
  godess(pix, list, tab);
  return (0);
}

int	letter_M(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "10001";
  tab[1] = "11011";
  tab[2] = "10101";
  tab[3] = "10001";
  tab[4] = "10001";
  godess(pix, list, tab);
  return (0);
}

int	letter_N(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "10001";
  tab[1] = "11001";
  tab[2] = "10101";
  tab[3] = "10011";
  tab[4] = "10001";
  godess(pix, list, tab);
  return (0);
}

int	letter_O(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "11111";
  tab[1] = "10001";
  tab[2] = "10001";
  tab[3] = "10001";
  tab[4] = "11111";
  godess(pix, list, tab);
  return (0);
}
