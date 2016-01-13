/*
** gen.c for gen in /home/alies/rendu/gfx_tekdoom
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan 13 14:43:11 2016 Arnaud Alies
** Last update Wed Jan 13 15:51:37 2016 Arnaud Alies
*/

#include "map.h"

t_map	*map_gen(int size)
{
  t_map	*res;
  int	x;
  int	max;

  max = (size * size * size)
  if ((res = malloc(sizeof(t_map))) == NULL)
    return (NULL);
  (res->head).version = MAP_VERSION;
  (res->head).size = size;
  (res->head).offset = 0;
  x = 0;
  if ((res->blocks = malloc(sizeof(t_block) * max)) == NULL)
    return (NULL);
  while (x < max)
    {
      ((res->blocks)[x]).x = 0;
      x = 1;
    }
  return (res);
}
