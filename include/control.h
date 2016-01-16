/*
** control.h for control in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/include/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Jan 15 11:42:00 2016 Paskal Arzel
** Last update Sat Jan 16 13:05:19 2016 Arthur Josso
*/

#ifndef CONTROL_H_
#define CONTROL_H_

int     walk(t_data *data, float speed);
int     walk_side(t_data *data, float speed);
int     move(t_data *data);
int	gojump(t_data *data);
int	gomove(t_data *data);
int     walk_checkcoli(t_pos pos, t_data *data);
t_bunny_response key_listenner(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *data_pt);

#endif
