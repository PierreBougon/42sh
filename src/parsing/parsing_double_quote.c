/*
** parsing_double_quote.c for parsing_double_quote in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Thu Jun  2 10:43:51 2016 marel_m
** Last update Thu Jun  2 14:38:50 2016 marel_m
*/

#include "42s.h"

int	pos_double_quote(char *str, char c)
{
  int	i;
  int	quote;

  i = my_strlen(str) - 1;
  quote = 0;
  while (i > 0)
    {
      if (str[i] == '"')
	quote++;
      else if (str[i] == c && quote % 2 == 0)
	return (quote);
      i--;
    }
  return (quote);
}

int	double_quote_redir(char *str)
{
  int	i;
  int	quote;

  i = 0;
  quote = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == '"')
	quote++;
      else if ((str[i] == '>' || str[i] == '<') && quote % 2 == 0)
	return (quote);
      i++;
    }
  return (quote);
}

int	check_quote(char *str, char c1, char c2)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str && str[i] != '\0' && str[i] != c1 && str[i] != c2)
    {
      if (str[i] == '"')
	nb++;
      i++;
    }
  return (nb);
}
