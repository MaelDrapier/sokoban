/*
** my_sokoban.h for my_sokoban in /home/mael.drapier/PSU_2016_my_sokoban
** 
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
** 
** Started on  Wed Dec 14 12:35:43 2016 mael drapier
** Last update Tue Dec 20 18:17:00 2016 mael drapier
*/

#ifndef MY_SOKOBAN_H_
# define MY_SOKOBAN_H_

# include "struct.h"
# define RETURN_SUCCESS 0
# define RETURN_FAIL 84

void	my_putstr(int fd, char *str);
int	init_map(t_map *map);
char	**create_tab(t_map *map, char **tab, int k);
void	free_this(char **tab, t_map *map);
void	display_game(char **tab, t_map *map);
int	is_free(char **tab, int y, int x);
void	set_direction(int ch, t_map * map);
void	event_move_box(char **tab,t_map * map);
int	check_win(char **tab, t_map *map);
int	check_lose(char **tab, t_map *map, int res);
void	win_screen(t_map *map);

#endif /* !MY_SOKOBAN_H_ */
