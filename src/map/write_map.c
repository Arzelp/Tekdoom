/*
** write_map.c for write map in /home/alies/rendu/gfx_tekdoom
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan 13 13:55:50 2016 Arnaud Alies
** Last update Wed Jan 13 14:11:08 2016 Arnaud Alies
*/

int	write_map(t_map *map, const char *name)
{
  int	fd;
  int	w;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (1);
  if (write(fd, &(map->head), sizeof(map->head)) != sizeof(map->head))
    return (1);
  
}
