/*
** my_get_next_line.c for my_get_next_line in /home/marel_m/Colles/func_spe
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Apr 19 11:03:29 2016 marel_m
** Last update Thu May 19 10:06:07 2016 Mathieu Sauvau
*/

#include <string.h>
#include "get_next_line.h"

char	*my_realloc(char *str, int size)
{
  char	*tmp;
  int	i;

  if ((tmp = malloc(size + 1)) == NULL)
    return (NULL);
  i = -1;
  while (str[++i] && i < size)
    tmp[i] = str[i];
  while (i <= size)
    tmp[i++] = 0;
  if (str != NULL)
    free(str);
  return (tmp);
}

char	*last_buff(char *buff, int *ret, int *i, int *j)
{
  char	*str;
  int	size;

  if ((str = malloc(1)) == NULL || *ret == 0)
    return (NULL);
  str[0] = 0;
  size = 0;
  if (*i < READ_SIZE && *i != -1)
    while (buff[++(*i)] && buff[*i] != '\n')
      {
	size++;
	if ((str = my_realloc(str, size)) == NULL)
	  return (NULL);
	str[++(*j)] = buff[(*i)];
      }
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1];
  static int	i = -1;
  static int	ret = -1;
  char		*str;
  int		size;
  int		j;

  str = NULL;
  j = -1;
  if ((fd < 0) || READ_SIZE < 1 ||
      (str = last_buff(buff, &ret, &i, &j)) == NULL || buff[i] == '\n')
    return (str);
  size = j + 1;
  while (buff[i] != '\n' && (ret = read(fd, buff, READ_SIZE)) > 0
	 && (size += ret))
    {
      buff[ret] = 0;
      if ((str = my_realloc(str, size)) == NULL)
	return (NULL);
      i = -1;
      while (buff[++i] && buff[i] != '\n')
	str[++j] = buff[i];
    }
  if (ret == 0)
    {
      memset(buff, 0, sizeof(buff));
      i = -1;
      ret = -1;
    }
  if (size)
    return (str);
  return (free(str), NULL);
}
