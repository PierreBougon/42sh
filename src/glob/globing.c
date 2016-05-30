/*
** globing.c for azd in /home/debrau_c/Documents/cours/PSU/glob_easy
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Thu May 26 20:52:45 2016 debrau_c
** Last update Mon May 30 15:16:37 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include "my_glob.h"

static char	**glob_str_tab(char *str)
{
  char		**newer;
  int		nb;
  int		i;
  int		j;

  nb = glob_count_occur(str, ' ');
  if (!(newer = malloc(sizeof(char *) * (nb + 1))))
    return (NULL);
  i = -1;
  j = 0;
  while (++i < nb)
    {
      if ((newer[i] = glob_strcdup(&str[j], ' ')) == NULL)
	return (NULL);
      j += glob_strclen(&str[j], ' ') + 1;
    }
  newer[i] = NULL;
  return (newer);
}

static char	*glob_new_str(char *past, glob_t *buf)
{
  unsigned int	i;
  unsigned int	size;

  i = 0;
  while (i < buf->gl_pathc)
    {
      size = glob_strlen(past) + glob_strlen(buf->gl_pathv[i]);
      if ((past = glob_realloc(past, size + 1)) == NULL)
	return (NULL);
      glob_strcat(past, " ");
      glob_strcat(past, buf->gl_pathv[i]);
      i++;
    }
  return (past);
}

static int	glob_no_match_recup(char **newer, char **tab, int i)
{
  int		size;

  size = glob_strlen(tab[i]) + glob_strlen(*newer) + 2;
  if ((*newer = glob_realloc(*newer, size)) == NULL)
    return (1);
  strcat(*newer, " ");
  strcat(*newer, tab[i]);
  return (0);
}
static char	*globing_do(char **tab)
{
  int		i;
  char		*newer;
  glob_t	*buf;
  int		rep;

  newer = NULL;
  i = -1;
  if ((buf = malloc(sizeof(glob_t))) == NULL)
    return (NULL);
  while (tab && tab[++i] != NULL)
    {
      rep = glob(tab[i], 0, NULL, buf);
      if (rep == GLOB_NOMATCH)
	{
	  if (glob_no_match_recup(&newer, tab, i))
	    return (NULL);
	}
      else if (rep == 0)
	if (buf->gl_pathc > 0)
	  if ((newer = glob_new_str(newer, buf)) == NULL)
	    return (NULL);
      globfree(buf);
    }
  free(buf);
  return (newer);
}

int	globing(char **str)
{
  char	**recup;

  if ((recup = glob_str_tab(*str)) == NULL)
    return (1);
  free(*str);
  if ((*str = globing_do(recup)) == NULL)
    return (1);
  glob_epur(*str);
  glob_clean_tab(recup);
  return (0);
}
