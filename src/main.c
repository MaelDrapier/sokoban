/*
** main.c for my_sokoban in /home/mael.drapier/PSU_2016_my_sokoban
**
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
**
** Started on  Wed Dec 14 11:45:03 2016 mael drapier
** Last update Tue Dec 20 16:10:04 2016 mael drapier
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_sokoban.h"

int	my_read_map(char *str, t_map *map)
{
  int	fd;

  if ((map->buf = malloc(sizeof(char) * 4096)) == NULL)
    return (RETURN_FAIL);
  fd = open(str, O_RDONLY);
  if (fd == -1)
    {
      my_putstr(2, "ERROR: Can not open file '");
      my_putstr(2, str);
      my_putstr(2, "'\n");
      return (RETURN_FAIL);
    }
  if (read(fd, map->buf, 4095) < 0)
    return (RETURN_FAIL);
  map->buf[4096] = '\0';
  init_map(map);
  free(map->buf);
  return (RETURN_SUCCESS);
}

int	main(int ac, char **av)
{
  int	res;
  t_map	*map;

  if ((map = malloc(sizeof(*map))) == NULL)
    return (RETURN_FAIL);
  res = RETURN_SUCCESS;
  if (ac != 2)
    {
      my_putstr(2, "ERROR: too few or too much arguments\n");
      return (RETURN_FAIL);
    }
  if (av[1][0] == '-' && av[1][1] == 'h')
    {
      my_putstr(1, "USAGE\n\t\t./my_sokoban map.txt\nDESCRIPTION\n");
      my_putstr(1, "map.txt\t\tFile representing the warehouse map, ");
      my_putstr(1, "containing '#' for walls,\n\t\t'P' for the player,");
      my_putstr(1, " 'X' for boxes and 'O' for storage locations.\n");
      my_putstr(1, "HOW TO PLAY\n\t\tPress 'ZQSD' keys to move,");
      my_putstr(1, " -SPACE- to reset the game and 'Q' to quit.\n");
      my_putstr(1, "\t\tPush all the boxes on storage locations to win.\n");
      my_putstr(1, "AUTHOR\n\t\tMade by Mael Drapier\n");
      return (RETURN_SUCCESS);
    }
  res = my_read_map(av[1], map);
  return (res);
}
