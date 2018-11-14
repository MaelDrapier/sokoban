/*
** bonus_win.c for my_sokoban in /home/mael.drapier/PSU_2016_my_sokoban/bonus
** 
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
** 
** Started on  Tue Dec 20 18:08:35 2016 mael drapier
** Last update Tue Dec 20 18:25:48 2016 mael drapier
*/

#include <ncurses.h>
#include "my_sokoban.h"

void	win_screen(t_map *map)
{
  int	ch;
  int	y;
  int	x;

  ch = 0;
  clear();
  while (ch != 32)
    {
      y = LINES / 2;
      x = COLS / 2;
      if (LINES < 7 || COLS < 22)
	mvprintw(LINES / 2, x - 10, "enlarge the terminal");
      else
	{
	  mvprintw(y - 3, x - 10, "CONGRATULATIONS !!!");
	  mvprintw(y, x - 10, "You solved the puzzle");
	  mvprintw(y + 1, x - 10, "with only %d moves !", map->nb_moves);
	  mvprintw(y + 3, x - 10, "Press -SPACE- to quit");
	}
      ch = getch();
      clear();
      refresh();
    }
}
