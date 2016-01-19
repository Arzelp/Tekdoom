/*
** save_map.c for save map in /home/alies_a/rendu/gfx_tekdoom
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan 19 15:46:45 2016 alies_a
** Last update Tue Jan 19 15:59:38 2016 alies_a
*/

#include <lapin.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "map.h"

int	map_save(t_map *map, const char *name)
{
  int	fd;
  int	max;
  int	x;

  x = 0;
  max = (map->head).size * (map->head).size * (map->head).size;//yolo
  if ((fd = open(name, O_CREAT | O_WRONLY, 0666)) == -1)
    return (1);
  write(fd, &(map->head), sizeof(t_map_head));
  while (x < max)
    {
      write(fd, &((map->blocks)[x]), sizeof(t_block));
      x += 1;
    }
  close(fd);
}
