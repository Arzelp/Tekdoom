/*
** PT.c for PT.c in /home/arzel_p/rendu/sandbox/Lapinou/Police/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Jan 25 21:12:01 2016 Paskal Arzel
** Last update Tue Jan 26 14:49:58 2016 Paskal Arzel
*/

#include <stdlib.h>
#include "lapin.h"
#include "police.h"

int	letter_P(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "11110";
  tab[1] = "10001";
  tab[2] = "11110";
  tab[3] = "10000";
  tab[4] = "10000";
  godess(pix, list, tab);
  return (0);
}

int	letter_Q(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "01110";
  tab[1] = "10010";
  tab[2] = "10110";
  tab[3] = "01110";
  tab[4] = "00001";
  godess(pix, list, tab);
  return (0);
}

int	letter_R(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "11110";
  tab[1] = "10001";
  tab[2] = "11110";
  tab[3] = "10001";
  tab[4] = "10001";
  godess(pix, list, tab);
  return (0);
}

int	letter_S(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "11111";
  tab[1] = "10000";
  tab[2] = "11111";
  tab[3] = "00001";
  tab[4] = "11111";
  godess(pix, list, tab);
  return (0);
}

int	letter_T(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "11111";
  tab[1] = "00100";
  tab[2] = "00100";
  tab[3] = "00100";
  tab[4] = "00100";
  godess(pix, list, tab);
  return (0);
}
