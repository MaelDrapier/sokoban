/*
** game.c for my_sokoban in /home/mael.drapier/PSU_2016_my_sokoban
** 
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
** 
** Started on  Wed Dec 14 14:05:40 2016 mael drapier
** Last update Tue Dec 20 18:28:10 2016 mael drapier
*/

#include <ncurses.h>
#include "my_sokoban.h"

char	**event_reset(int ch, char **tab, t_map *map)
{
  map->i = map->i;
  if (ch == 32)
    {
      free_this(tab, map);
      map->i = 0;
      map->j = 0;
      tab = create_tab(map, tab, 0);
      map->nb_moves = 0;
      return (tab);
    }
  return (tab);
}

int	event_quit(int ch)
{
  if (ch == 113)
    return (0);
  return (1);
}

int	is_free(char **tab, int y, int x)
{
  if (tab[y][x] == ' ')
    return (1);
  if (tab[y][x] == 'O')
    return (2);
  if (tab[y][x] == 'X')
    return (-1);
  if (tab[y][x] == 'x')
    return (-2);
  return (0);
}

int	display_more(char **tab, t_map *map, int i)
{
  int	ch;
  int	x;
  int	y;

  while (map->j < map->height)
    {
      y = LINES / 2 + map->j;
      x = COLS / 2;
      if (COLS < map-> width || LINES < map->height + 1)
	mvprintw(LINES / 2, x - 10, "enlarge the terminal");
      else
	mvprintw(y - map->height / 2, x - map->width / 2, tab[map->j]);
      map->j = map->j + 1;
    }
  y = LINES / 2 - map->height / 2 - 1;
  mvprintw(y, x - map->width / 2, "MOVES: %d", map->nb_moves);
  refresh();
  ch = getch();
  tab = event_reset(ch, tab, map);
  set_direction(ch, map);
  event_move_box(tab, map);
  if (event_quit(ch) == 0)
    return (0);
  i = check_win(tab, map);
  return (i);
}

void	display_game(char **tab, t_map *map)
{
  int	i;

  i = 1;
  initscr();
  curs_set(FALSE);
  raw();
  keypad(stdscr, TRUE);
  noecho();
  map->nb_moves = 0;
  while (i == 1)
    {
      clear();
      map->j = 0;
      i = display_more(tab, map, i);
    }
  if (map->i == -111)
    win_screen(map);
  endwin();
}
