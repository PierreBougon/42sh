/*
** my_realloc.c for my_realloc in /home/marel_m/Rendu/Piscine_C/Piscine_C_workshoplib/lib/my
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Nov 23 11:36:14 2015 maud marel
** Last update Mon May 30 22:37:51 2016 marel_m
*/

#include <string.h>
#include <stdlib.h>

char	**my_realloc_tab(char **old, int size)
{
  char	**new;
  int	l;

  if ((new = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  l = 0;
  while (old && old[l] != NULL)
    {
      new[l] = strdup(old[l]);
      free(old[l]);
      l++;
    }
  free(old[l]);
  free(old);
  return (new);
}

char	**my_realloc_tabadd(char **tab, int add_lines)
{
  char	**new_tab;
  int	act_lines;
  int	j;

  act_lines = -1;
  while (tab[++act_lines] != NULL);
  if ((new_tab = malloc(sizeof(char *)
			      * (act_lines + add_lines + 1))) == NULL)
    return (NULL);
  new_tab[act_lines + add_lines] = NULL;
  j = -1;
  while (++j < act_lines)
    new_tab[j] = tab[j];
  free(tab);
  return (new_tab);}
