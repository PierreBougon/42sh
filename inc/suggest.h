/*
** suggest.h for suggest in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu May 26 01:43:16 2016 bougon_p
** Last update Thu May 26 13:06:20 2016 bougon_p
*/

#ifndef SUGGEST_H_
# define SUGGEST_H_

typedef struct		s_suggest
{
  int			dist_min;
  int			nb_bin;
  char			**binaries;
  int			*tab_dist;
}			t_suggest;

typedef struct	s_sh	t_sh;

int	suggest(t_sh *, char *);
int	levenshtein(char *, char *);
int	check_all_path(t_sh *, t_suggest *);
char	**my_realloc_tabadd(char **, int);

#endif /* !SUGGEST_H_ */
