/*
** my.h for my.h in /home/arzel_p/rendu/sandbox/Lapinou/Police/include/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Jan 25 14:03:28 2016 Paskal Arzel
** Last update Tue Jan 26 14:41:24 2016 Paskal Arzel
*/

typedef struct s_pol
{
  t_bunny_position		*pos;
  t_color			*color;
  int				size;
}t_pol;

int	police(t_bunny_pixelarray *pix, t_pol *list, char *str);
int	checkletter(t_bunny_pixelarray *pix, t_pol *list, char c);
int	checkletterplus(t_bunny_pixelarray *pix, t_pol *list, char c);
int	godess(t_bunny_pixelarray *pix, t_pol *list, char **tab);
int	gocarre(t_bunny_pixelarray *pix, t_pol *list);
int	letter_A(t_bunny_pixelarray *pix, t_pol *list);
int	letter_B(t_bunny_pixelarray *pix, t_pol *list);
int	letter_C(t_bunny_pixelarray *pix, t_pol *list);
int	letter_D(t_bunny_pixelarray *pix, t_pol *list);
int	letter_E(t_bunny_pixelarray *pix, t_pol *list);
int	letter_F(t_bunny_pixelarray *pix, t_pol *list);
int	letter_G(t_bunny_pixelarray *pix, t_pol *list);
int	letter_H(t_bunny_pixelarray *pix, t_pol *list);
int	letter_I(t_bunny_pixelarray *pix, t_pol *list);
int	letter_J(t_bunny_pixelarray *pix, t_pol *list);
int	letter_K(t_bunny_pixelarray *pix, t_pol *list);
int	letter_L(t_bunny_pixelarray *pix, t_pol *list);
int	letter_M(t_bunny_pixelarray *pix, t_pol *list);
int	letter_N(t_bunny_pixelarray *pix, t_pol *list);
int	letter_O(t_bunny_pixelarray *pix, t_pol *list);
int	letter_P(t_bunny_pixelarray *pix, t_pol *list);
int	letter_Q(t_bunny_pixelarray *pix, t_pol *list);
int	letter_R(t_bunny_pixelarray *pix, t_pol *list);
int	letter_S(t_bunny_pixelarray *pix, t_pol *list);
int	letter_T(t_bunny_pixelarray *pix, t_pol *list);
int	letter_U(t_bunny_pixelarray *pix, t_pol *list);
int	letter_V(t_bunny_pixelarray *pix, t_pol *list);
int	letter_W(t_bunny_pixelarray *pix, t_pol *list);
int	letter_X(t_bunny_pixelarray *pix, t_pol *list);
int	letter_Y(t_bunny_pixelarray *pix, t_pol *list);
int	letter_Z(t_bunny_pixelarray *pix, t_pol *list);
