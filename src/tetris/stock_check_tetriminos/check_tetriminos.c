/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_bstetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Feb 23 15:11:43 2016 maud marel
** Last update Sun Jun  5 14:51:03 2016 bougon_p
*/

#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include "tetris.h"

int		stock_tetriminos(char *str, t_tetris *tetris)
{
  int		fd;
  char		*file;
  char		*way;

  if (!(way = strdup(tetris->tetri_file)) ||
      !(way = my_realloc(way, strlen(way) + strlen(str) + 1)))
    return (-1);
  strcat(way, str);
  if ((fd = open(way, O_RDONLY)) == -1)
    return (-1);
  if ((file = get_next_line(fd)) == NULL)
    {
      if (check_empty(tetris, str) == -1)
	return (-1);
      free(way);
      return (free(file), 0);
    }
  if (stock(file, tetris, fd, str) == -1)
    return (-1);
  free(file);
  while ((file = get_next_line(fd)) != NULL)
    free(file);
  if (close(fd) == -1)
    return (-1);
  return (free(way), 0);
}

int	check_end_tetri(t_tetris *tetris, char *name)
{
  int	size;

  size = my_strlen(name) - 1;
  if (name[size - 9] != '.' || name[size - 8] != 't'
      || name[size - 7] != 'e' || name[size - 6] != 't'
      || name[size - 5] != 'r' || name[size - 4] != 'i'
      || name[size - 3] != 'm' || name[size - 2] != 'i'
      || name[size - 1] != 'n' || name[size] != 'o')
    {
      if (my_strlen(name) != 1 && my_strlen(name) != 2)
	{
	  tetris->list_tetri->nb_tetri--;
	  return (-1);
	}
      return (1);
    }
  return (0);
}

int	check_first(t_tetris *tetris, char *name)
{
  int	nb;

  if ((nb = check_end_tetri(tetris, name)) == -1)
    return (-1);
  else if (nb == 1)
    return (0);
  if (stock_tetriminos(name, tetris) == -1)
    return (-1);
  return (0);
}

int		check_tetriminos(t_tetris *tetris)
{
  DIR		*dirp;
  struct dirent	*entry;

  if ((dirp = opendir(tetris->tetri_file)) == NULL)
    {
      my_putstr_error("Not existing directory tetriminos\n");
      return (-1);
    }
  if (tcreate_list(tetris) == -1)
    return (-1);
  tetris->list_tetri->nb_tetri = -2;
  tetris->list_tetri->nb_error = 0;
  while ((entry = readdir(dirp)) != NULL)
    {
      tetris->list_tetri->nb_tetri++;
      if (check_first(tetris, entry->d_name) == -1)
	return (-1);
    }
  if (tetris->list_tetri->nb_tetri == 0)
    {
      my_putstr_error("No tetrimino exiting\n");
      return (-1);
    }
  free(dirp);
  return (0);
}
