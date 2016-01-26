/*
** police.c for police in /home/arzel_p/rendu/sandbox/Lapinou/Police/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Jan 25 13:55:20 2016 Paskal Arzel
** Last update Tue Jan 26 14:49:30 2016 Paskal Arzel
*/

#include <stdlib.h>
#include <lapin.h>
#include "police.h"

int	checkletter(t_bunny_pixelarray *pix, t_pol *list, char c)
{
  int	nb;
  int	(*fonc[15])(t_bunny_pixelarray *, t_pol *);

  nb = c - 'A';
  fonc[0] = &letter_A;
  fonc[1] = &letter_B;
  fonc[2] = &letter_C;
  fonc[3] = &letter_D;
  fonc[4] = &letter_E;
  fonc[5] = &letter_F;
  fonc[6] = &letter_G;
  fonc[7] = &letter_H;
  fonc[8] = &letter_I;
  fonc[9] = &letter_J;
  fonc[10] = &letter_K;
  fonc[11] = &letter_L;
  fonc[12] = &letter_M;
  fonc[13] = &letter_N;
  fonc[14] = &letter_O;
  if (nb > 14)
    checkletterplus(pix, list, c);
  else if (nb <= 14 && nb >= 0)
    fonc[nb](pix, list);
  return (0);
}

int	checkletterplus(t_bunny_pixelarray *pix, t_pol *list, char c)
{
  int	nb;
  int	(*fonc[15])(t_bunny_pixelarray *, t_pol *);

  nb = c - 'P';
  fonc[0] = &letter_P;
  fonc[1] = &letter_Q;
  fonc[2] = &letter_R;
  fonc[3] = &letter_S;
  fonc[4] = &letter_T;
  fonc[5] = &letter_U;
  fonc[6] = &letter_V;
  fonc[7] = &letter_W;
  fonc[8] = &letter_X;
  fonc[9] = &letter_Y;
  fonc[10] = &letter_Z;
  if (nb <= 10 && nb >= 0)
    fonc[nb](pix, list);
  return (0);
}

int	police(t_bunny_pixelarray *pix, t_pol *list, char *str)
{
  int	i;

  if (str == NULL)
    return (1);
  i = 0;
  while (str[i])
    {
      checkletter(pix, list, str[i]);
      list->pos->x = list->pos->x + 6 * list->size;
      i++;
    }
  return (0);
}
