/*
** epure_str.c for epure_str in /home/marel_m/Rendu/Semestre_2/PSU/42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed Apr 27 18:10:05 2016 marel_m
** Last update Wed Apr 27 18:23:35 2016 marel_m
*/

#include <stdlib.h>

char	*epure_str(char *str)
{
  char	*new;
  int	i;
  int	j;

  if ((new = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i] != '\0' && str)
    {
      new = take_off_space(str, new, &i, &j);
      if (str[i] != '\0' && str)
	new[j] = str[i];
      j++;
      i++;
    }
  new[j] = '\0';
  return (new);
}
