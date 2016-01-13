/*
** map.h for map in /home/alies/rendu/gfx_tekdoom
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Wed Jan 13 13:36:19 2016 Arnaud Alies
** Last update Wed Jan 13 20:24:23 2016 Arnaud Alies
*/

#ifndef MAP_H_
#define MAP_H_

#define MAP_VERSION (1)

#include <stdint.h>
#include "doom.h"

int	map_print(t_map *map);
t_map   *map_gen(int size);
t_block *map_get(t_map *map, t_pos *pos);
int	map_check_pos(t_map *map, t_vec *vec);
int     map_set(t_map *map, t_pos *pos, t_block block);
void	map_set_flat(t_map *map);
void	map_set_wall(t_map *map);

#endif
