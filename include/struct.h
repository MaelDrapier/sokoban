/*
** struct.h for my_sokoban in /home/mael.drapier/PSU_2016_my_sokoban
** 
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
** 
** Started on  Wed Dec 14 13:41:44 2016 mael drapier
** Last update Tue Dec 20 17:32:29 2016 mael drapier
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef	struct		s_map
{
  int			width;
  int			height;
  int			i;
  int			j;
  int			p_x;
  int			p_y;
  int			n_x;
  int			n_y;
  char			*buf;
  int			*spot;
  int			end_spot;
  int			nb_moves;
}			t_map;

#endif /* !STRUCT_H_ */
