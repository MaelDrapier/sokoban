/*
** display.c for my_sokoban in /home/mael.drapier/PSU_2016_my_sokoban
** 
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
** 
** Started on  Wed Dec 14 12:33:44 2016 mael drapier
** Last update Sun Dec 18 20:37:39 2016 mael drapier
*/

#include <unistd.h>
#include "my_sokoban.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

void	my_putstr(int fd, char *str)
{
  write(fd, str, my_strlen(str));
}
