/*
** control.h for control in /home/arzel_p/rendu/gfx_tekdoom/gfx_tekdoom/include/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Jan 15 11:42:00 2016 Paskal Arzel
** Last update Fri Jan 15 11:42:56 2016 Paskal Arzel
*/

#ifndef CONTROL_H_
#define CONTROL_H_

int     walk(t_data *data, int speed);
int     move(t_data *data);
t_bunny_response key_listenner(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *data_pt);

#endif
