/*
** control.h for control in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/include/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Jan 15 11:42:00 2016 Paskal Arzel
** Last update Mon Jan 18 01:26:08 2016 Paskal Arzel
*/

#ifndef CONTROL_H_
#define CONTROL_H_

int     walk(t_data *data, float speed, int size);
int     walk_side(t_data *data, float speed, int size);
int     move(t_data *data);
int	gojump(t_data *data);
int	gomove(t_data *data);
void	map_create_block(t_data *data);
int     walk_checkcoli(t_pos pos, t_data *data, int size);
int	drawjauge(t_data *data, t_bunny_pixelarray *pix);
int	makelines(t_bunny_pixelarray *pix, t_color *color);
int	filljauge(t_data *data, t_bunny_pixelarray *pix, t_color *color);
int	drawsquare(t_bunny_pixelarray *pix, t_bunny_position pos,
		   t_bunny_position pos2, t_color *color);
t_bunny_response key_listenner(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *data_pt);
void	map_create_block(t_data *data);
void	map_delete_block(t_data *data);

#endif
