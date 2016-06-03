/*
** check_good_double_quote.c for check_good_double_quote in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Thu Jun  2 15:07:00 2016 marel_m
** Last update Fri Jun  3 15:26:02 2016 marel_m
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

void	write_message(int pos_s, int pos_d)
{
  if (pos_d < pos_s)
      write(2, "Unmatched \".\n", 13);
  else
    write(2, "Unmatched \'.\n", 13);
}

void	message_fail_quote(char *str, int quote_s, int quote_d, int pos_s)
{
  int	i;
  int	pos_d;

  i = -1;
  pos_d = 0;
  while (str && str[++i] != '\0')
    {
      if (str[i] == 39)
	{
	  quote_s++;
	  if (quote_s % 2 == 0)
	    quote_s = 0;
	  else
	    pos_s = i;
	}
      else if (str[i] == '"')
	{
	  quote_d++;
	  if (quote_d % 2 == 0)
	    quote_d = 0;
	  else
	    pos_d = i;
	}
    }
  write_message(pos_s, pos_d);
}

int	check_good_quote(t_sh *sh, char *str)
{
  int	i;
  int	quote_s;
  int	quote_d;

  i = -1;
  quote_s = 0;
  quote_d = 0;
  while (str && str[++i] != '\0')
    {
      if (str[i] == 39)
	quote_s++;
      else if (str[i] == '"')
	quote_d++;
    }
  if (quote_d % 2 != 0 && quote_s % 2 != 0)
    return (sh->exit = 1, message_fail_quote(str, 0, 0, 0), 1);
  if (quote_s % 2 != 0)
    return (sh->exit = 1, write(2, "Unmatched \'.\n", 13), 1);
  else if (quote_d % 2 != 0)
    return (sh->exit = 1, write(2, "Unmatched \".\n", 13), 1);
  return (0);
}

char	*replace_single_quote(char *str)
{
  char	*new;
  int	i;

  if ((new = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == '"')
	{
	  new[i] = '"';
	while (str[++i] != '\0' && str[i] != '"')
	  new[i] = str[i];
	new[i] = '"';
	}
      else if (str[i] == 39)
	new[i] = '"';
      else
	new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  free(str);
  return (new);
}

char	*check_good_quote_replace_quote(t_sh *sh, char *str)
{
  if (str == NULL
      || check_good_quote(sh, str)
      || (str = replace_single_quote(str)) == NULL)
    return (NULL);
  return (str);
}
