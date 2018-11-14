/*
** map_tab.c for bsq in /home/mael.drapier/PSU_2016_my_sokoban
** 
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
** 
** Started on  Mon Dec 12 13:39:47 2016 mael drapier
** Last update Tue Dec 20 16:13:55 2016 mael drapier
*/

#include <stdlib.h>
#include "my_sokoban.h"

char	**create_tab(t_map *map, char **tab, int k)
{
  if ((tab = malloc(sizeof(char*) * (map->height + 1))) == NULL)
    return (NULL);
  while (map->j < map->height)
    {
      if ((tab[map->j] = malloc(sizeof(char) * (map->width + 1))) == NULL)
	return (NULL);
      while (map->i < map->width)
	{
	  tab[map->j][map->i] = map->buf[k];
	  if (map->buf[k] == 'P')
	    map->p_x = map->i;
	  if (map->buf[k] == 'P')
	    map->p_y = map->j;
	  if (map->buf[k] == '\n')
	    tab[map->j][map->i + 1] = '\0';
	  if (map->buf[k] == '\n')
	    map->i = map->width;
	  else
	    k = k + 1;
	  map->i = map->i + 1;
	}
      k = k + 1;
      map->i = 0;
      map->j = map->j + 1;
    }
  return (tab);
}

void	free_this(char **tab, t_map *map)
{
  map->j = 0;
  while (map->j < map->height)
    {
      free(tab[map->j]);
      map->j = map->j + 1;
    }
  free(tab);
}

void	init_spot(char **tab, t_map *map)
{
  int	k;

  k = 0;
  map->i = 0;
  map->j = 0;
  while (map->j < map->height)
    {
      while (map->i < map->width)
	{
	  if (tab[map->j][map->i] == 'O')
	    {
	      map->spot[k] = map->j;
	      map->spot[k + 1] = map->i;
	      k = k + 2;
	    }
	  map->i = map->i + 1;
	}
      map->i = 0;
      map->j = map->j + 1;
    }
  map->end_spot = k;
}

void	init_width(t_map *map)
{
  int	res;

  res = 0;
  map->i = 0;
  map->width = 0;
  while (map->buf[map->i] != '\0')
    {
      if (map->buf[map->i] == '\n')
	{
	  if (res > map->width)
	    map->width = res - 1;
	  res = 0;
	}
      map->i = map->i + 1;
      res = res + 1;
    }
}

int	init_map(t_map *map)
{
  char	**tab;

  tab = NULL;
  map->height = 0;
  if ((map->spot = malloc(sizeof(int) * 1000)) == NULL)
    return (RETURN_FAIL);
  init_width(map);
  map->i = 0;
  while (map->buf[map->i] != '\0')
    {
      if (map->buf[map->i] == '\n')
	map->height = map->height + 1;
      map->i = map->i + 1;
    }
  map->i = 0;
  map->j = 0;
  tab = create_tab(map, tab, 0);
  if (tab == NULL)
    return (RETURN_FAIL);
  init_spot(tab, map);
  display_game(tab, map);
  free_this(tab, map);
  return (RETURN_SUCCESS);
}
