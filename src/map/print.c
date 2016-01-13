/*
** print.c for print map in /home/alies/rendu/gfx_tekdoom
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan 13 17:31:45 2016 Arnaud Alies
** Last update Wed Jan 13 20:26:25 2016 Arnaud Alies
*/

#include <stdio.h>
#include "map.h"
#include "my.h"

int		map_print(t_map *map)
{
  t_block	*block;
  t_pos		pos;
  int		size;

  size = (map->head).size;
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  printf("size: %d\n", size);
  while (pos.z < size)
    {
      block = map_get(map, &pos);
      printf("%d ", block->x);
      pos.x += 1;
      if (pos.x > size - 1)
	{
	  pos.x = 0;
	  pos.y += 1;
	  printf("\n");
	}
      if (pos.y > size - 1)
	{
	  pos.y = 0;
	  pos.z += 1;
	  printf("\n\n");
	}
    }
  return (0);
}
