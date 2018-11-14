/*
** event1.c for my_sokoban in /home/mael.drapier/PSU_2016_my_sokoban
** 
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
** 
** Started on  Thu Dec 15 11:58:37 2016 mael drapier
** Last update Tue Dec 20 17:59:53 2016 mael drapier
*/

#include <ncurses.h>
#include "my_sokoban.h"

void	set_direction(int ch, t_map *map)
{
  map->n_x = 0;
  map->n_y = 0;
  if (ch == KEY_LEFT)
    {
      map->n_x = -1;
      map->nb_moves = map->nb_moves + 1;
    }
  if (ch == KEY_RIGHT)
    {
      map->n_x = 1;
      map->nb_moves = map->nb_moves + 1;
    }
  if (ch == KEY_UP)
    {
      map->n_y = -1;
      map->nb_moves = map->nb_moves + 1;
    }
  if (ch == KEY_DOWN)
    {
      map->n_y = 1;
      map->nb_moves = map->nb_moves + 1;
    }
}

int	check_spot(t_map *map, int y, int x)
{
  int	i;

  i = 0;
  while (i < map->end_spot)
    {
      if (y == map->spot[i] && x == map->spot[i + 1])
	return(1);
      i = i + 2;
    }
  return (0);
}

void	event_move(char **tab, t_map *map)
{
  if (is_free(tab, map->p_y + map->n_y, map->p_x + map->n_x) > 0)
    {
      if (check_spot(map, map->p_y, map->p_x) == 1)
	tab[map->p_y][map->p_x] = 'O';
      else
	tab[map->p_y][map->p_x] = ' ';
      map->p_y = map->p_y + map->n_y;
      map->p_x = map->p_x + map->n_x;
      tab[map->p_y][map->p_x] = 'P';
    }
}

void	event_move_box(char **tab, t_map *map)
{
  if (is_free(tab, map->p_y + map->n_y, map->p_x + map->n_x) < 0)
    if (is_free(tab, map->p_y + map->n_y * 2, map->p_x + map->n_x * 2) > 0)
      {
	if (check_spot(map, map->p_y, map->p_x) == 1)
	  tab[map->p_y][map->p_x] = 'O';
	else
	  tab[map->p_y][map->p_x] = ' ';
	map->p_y = map->p_y + map->n_y;
	map->p_x = map->p_x + map->n_x;
	tab[map->p_y][map->p_x] = 'P';
	tab[map->p_y + map->n_y][map->p_x + map->n_x] = 'X';
      }
  event_move(tab, map);
}

int	check_win(char **tab, t_map *map)
{
  int	k;

  k = 0;
  while (k < map->end_spot)
    {
      map->j = map->spot[k];
      map->i = map->spot[k + 1];
      if (tab[map->j][map->i] != 'X')
	return (1);
      k = k + 2;
    }
  map->i = -111;
  return (0);
}
