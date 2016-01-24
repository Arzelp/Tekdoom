/*
** load_map.c for load map in /home/alies_a/rendu/gfx_tekdoom
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan 19 16:00:44 2016 alies_a
** Last update Sun Jan 24 13:48:56 2016 Arthur Josso
*/

#include <lapin.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "map.h"

t_map	*load_map(const char *name)
{
  t_map	*res;
  int	max;
  int	x;
  int	fd;

  if ((res = bunny_malloc(sizeof(t_map))) == NULL)
    return (NULL);
  if ((fd = open(name, O_RDONLY)) == -1)
    return (NULL);
  if (read(fd, &(res->head), sizeof(t_map_head)) != sizeof(t_map_head))
    return (NULL);
  x = 0;
  max = (res->head).size * (res->head).size * (res->head).size;
  if ((res->blocks = bunny_malloc(sizeof(t_block) * max)) == NULL)
    return (NULL);
  while (x < max)
    {
      if (read(fd, &((res->blocks)[x]), sizeof(t_block)) != sizeof(t_block))
	return (NULL);
      x += 1;
    }
  return (res);
}
