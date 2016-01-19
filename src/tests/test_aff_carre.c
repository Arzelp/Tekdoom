/*
** create_carre.c for create carre in /src/tests/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Mon Jan 18 17:32:59 2016 Frederic ODDOU
** Last update Mon Jan 18 17:32:59 2016 Frederic ODDOU
*/

#include <lapin.h>
#include <math.h>
#include "doom.h"
#include "map.h"
#include "control.h"

void		test_create_carre(t_map *map,
				  int large,
				  int lx,
				  int ly,
				  int z,
				  int texture)
{
  t_block x;
  t_pos pos;

  x.x = 1;
  x.texture = texture;
  pos.z = z;
  pos.x = lx;
  while (pos.x <= lx + large)
    {
      pos.y = ly;
      while (pos.y <= ly + large)
	{
	  if ((pos.x == lx || pos.x == lx + large) ||
	      (pos.y == ly || pos.y == ly + large))
	    map_set(map, &pos, x);
	  pos.y++;
	}
      pos.x++;
    }
}

void		test_aff_carre(t_map *map)
{
  t_block	x;
  t_pos		pos;

  pos.x = 6;
  pos.y = 1;
  pos.z = 1;
  while (pos.y <= 9)
    {
      map_set(map, &pos, x);
      pos.z++;
      pos.y++;
    }
  test_create_carre(map, 1, 15, 15, 1, 9);
  test_create_carre(map, 2, 14, 14, 2, 1);
  test_create_carre(map, 4, 13, 13, 3, 2);
  test_create_carre(map, 6, 12, 12, 4, 3);
  test_create_carre(map, 8, 11, 11, 5, 4);
  test_create_carre(map, 10, 10, 10, 4, 5);
  test_create_carre(map, 12, 9, 9, 3, 6);
  test_create_carre(map, 14, 8, 8, 2, 7);
  test_create_carre(map, 16, 7, 7, 1, 8);
}
