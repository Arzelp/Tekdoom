/*
** Z.c for Z in /home/arzel_p/rendu/sandbox/Lapinou/Police/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Jan 25 21:18:40 2016 Paskal Arzel
** Last update Tue Jan 26 14:50:07 2016 Paskal Arzel
*/

#include <stdlib.h>
#include "lapin.h"
#include "police.h"

int	letter_Z(t_bunny_pixelarray *pix, t_pol *list)
{
  char	*tab[5];

  tab[0] = "11111";
  tab[1] = "00010";
  tab[2] = "00100";
  tab[3] = "01000";
  tab[4] = "11111";
  godess(pix, list, tab);
  return (0);
}
