/*
** control.h for control in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/include/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Jan 15 11:42:00 2016 Paskal Arzel
** Last update Tue Jan 19 16:16:47 2016 Paskal Arzel
*/

#ifndef CONTROL_H_
#define CONTROL_H_

#define HUD (7)
#define STAJAU (5)
#define SPRMAX (100)
#define REGENSPR (0.15)
#define ACC (0.02)
#define INER (0.008)
#define VITMAX (0.12)
#define CAMSENS (0.07)

int     ctrl_walk(t_data *data, float speed, int size);
int     ctrl_walkside(t_data *data, float speed, int size);
int     ctrl_move(t_data *data);
int	ctrl_speed(t_data *data);
int	ctrl_inertie(t_data *data);
int	ctrl_gojump(t_data *data);
int	ctrl_gomove(t_data *data);
int     ctrl_checkcoli(t_pos pos, t_data *data, int size);
int	ctrl_camera(t_data *data);
int	ctrl_drawjauge(t_data *data, t_bunny_pixelarray *pix);
int	ctrl_fly(t_data *data);
int	ctrl_flymove(t_data *data, float speed);
int	ctrl_filljauge(t_data *data, t_bunny_pixelarray *pix, t_color *color);
int	ctrl_drawsquare(t_bunny_pixelarray *pix, t_bunny_position pos,
		   t_bunny_position pos2, t_color *color);
void	map_create_block(t_data *data);
void	map_delete_block(t_data *data);

#endif
