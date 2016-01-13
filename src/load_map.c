/*
** load_map.c for load map in /src/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Jan 13 13:58:52 2016 Frederic ODDOU
** Last update Wed Jan 13 13:58:52 2016 Frederic ODDOU
*/

t_map		*load_map(const char *file)
{
  t_map		*map;
  t_map_head	head;
  int		size;
  const int	fd;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  if ((size = read(fd, &head, sizeof(head))) != sizeof(head))
    return (NULL);
  if ((map = bunny_malloc(sizeof(*map))) == NULL)
    return (NULL);
  map->head = head;
  close(fd);
  return (map);
}
