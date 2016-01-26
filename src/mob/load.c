/*
** load.c for load in /home/alies_a/rendu/gfx_tekdoom
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan 26 17:26:31 2016 alies_a
** Last update Tue Jan 26 18:16:48 2016 alies_a
*/

#include "doom.h"
#include "bmp.h"

int     init_mob(t_data *data)
{
  int	x;

  if ((data->mob = bunny_malloc(sizeof(t_mob) * NB_MOB)) == NULL)
    return (1);
  if ((data->mob[0].tex_alive = load_bitmap("res/boss_alive.bmp")) == NULL)
    return (1);
  if ((data->mob[0].tex_hurt = load_bitmap("res/boss_hurt.bmp")) == NULL)
    return (1);
  if ((data->mob[0].tex_dead = load_bitmap("res/boss_dead.bmp")) == NULL)
    return (1);
  x = 0;
  while (x < NB_MOB)
    {
      data->mob[x].tex = data->mob[0].tex_alive;
      data->mob[x].pos.x = rand() % ((data->map)->head).size;
      data->mob[x].pos.y = rand() % ((data->map)->head).size;
      data->mob[x].pos.z = 1;
      data->mob[x].size.x = 2;
      data->mob[x].size.y = 5;
      data->mob[x].dead = 0;
      data->mob[x].speed = 0.005 * (rand() % 10 + 1);
      x += 1;
    }
  return (0);
}
