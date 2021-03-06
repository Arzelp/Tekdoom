/*
** load_bmp.c for bmp load in /home/alies/rendu/gfx_wolf3d/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Dec 10 17:19:58 2015 Arnaud Alies
** Last update Tue Jan 12 17:13:19 2016 Arnaud Alies
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <lapin.h>
#include "doom.h"
#include "bmp.h"

t_bunny_pixelarray      *load_pix(int fd)
{
  char                  buffer[4096];
  t_head                head;
  t_info                info;
  int                   r;

  r = read(fd, &head, sizeof(head));
  if (r != sizeof(head))
    return (NULL);
  r = read(fd, &info, sizeof(info));
  if (r != sizeof(info))
    return (NULL);
  r = head.offset - (sizeof(head) + sizeof(info));
  if (r > 0)
    read(fd, buffer, r);
  return (bunny_new_pixelarray(info.width, info.height));
}

void    c_rev(t_color *color)
{
  t_color buffer;

  buffer = *color;
  (color->argb)[0] = buffer.argb[3];
  (color->argb)[1] = buffer.argb[2];
  (color->argb)[2] = buffer.argb[1];
  (color->argb)[3] = buffer.argb[0];
}

int     read_init(t_bunny_pixelarray **pix,
		  t_bunny_position *pos,
		  int *fd,
		  const char *file)
{
  if ((*fd = open(file, O_RDONLY)) == -1)
    return (1);
  if ((*pix = load_pix(*fd)) == NULL)
    return (1);
  pos->x = 0;
  pos->y = ((*pix)->clipable).clip_height - 1;
  return (0);
}

t_bunny_pixelarray      *load_bitmap(const char *file)
{
  t_color               buffer;
  int                   r;
  int                   fd;
  t_bunny_position      pos;
  t_bunny_pixelarray    *pix;

  if (read_init(&pix, &pos, &fd, file))
    return (NULL);
  r = 1;
  while (r > 0)
    {
      r = read(fd, buffer.argb, 4);
      if (r == 4)
	{
	  c_rev(&buffer);
	  tekpixel(pix, &pos, &buffer);
	}
      pos.x += 1;
      pos.y = (pos.x >= (pix->clipable).clip_width ? pos.y - 1 : pos.y);
      pos.x = (pos.x >= (pix->clipable).clip_width ? 0 : pos.x);
    }
  close(fd);
  return (pix);
}
