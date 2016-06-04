/*
** my_put_in_word_tab.c for my_put_in_word_tab in /home/marel_m/Rendu/Systeme_Unix/PSU_2015_minishell1/lib/my
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan  6 14:52:17 2016 maud marel
** Last update Sat Jun  4 18:38:27 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

int	check_nb(char *str, char sign)
{
  int	i;
  int	nb;

  nb = 1;
  i = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == sign)
	nb++;
      while (str[i] != '\0' && str && str[i] == ' ')
      	i++;
      if (str[i] != '\0' && str)
	i++;
    }
  return (nb);
}

static int	check_first(t_tab *tab, char *str, char sign)
{
  int		i;

  tab->nb = check_nb(str, sign);
  tab->size = strlen(str);
  i = 0;
  if (tab->nb < 1)
    return (-1);
  while (str && str[i] == sign)
    i++;
  return (i);
}

void	my_strccpy(char *dest, char *src, char c, int *i)
{
  int	j;

  j = 0;
  while (src && src[*i] != '\0' && src[*i] != c)
    {
      dest[j] = src[*i];
      j++;
      (*i)++;
    }
  while (src[(*i)] && src[(*i)] == c)
    (*i)++;
  dest[j] = '\0';
}

char	**my_str_to_word_tab(char *str, char sign)
{
  int	i;
  int	l;
  char	**tab;
  t_tab	tb;

  if ((i = check_first(&tb, str, sign)) == -1
      || (tab = malloc(sizeof(char*) * (tb.nb + 2))) == NULL)
    return (NULL);
  l = 0;
  while (str[i] != '\0' && str[i])
    {
      if ((tab[l] = malloc(sizeof(char) * (tb.size + 2))) == NULL)
	return (NULL);
      if (str[i] == '"' && ++i)
	my_strccpy(tab[l], str, '"', &i);
      else
	my_strccpy(tab[l], str, sign, &i);
      l++;
    }
  tab[l] = NULL;
  return (tab);
}
