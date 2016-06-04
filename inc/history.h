/*
** history.h for ad in /home/debrau_c/Documents/cours/PSU/PSU_2015_42sh
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Sat Jun  4 20:35:09 2016 debrau_c
** Last update Sat Jun  4 20:35:10 2016 debrau_c
*/

#ifndef _HISTORY_H_
# define _HISTORY_H_

typedef struct		s_history
{
  char			*str;
  struct s_history	*next;
  struct s_history	*prev;
}			t_history;

typedef struct		s_head
{
  char			**path;
  char			*prompt;
  char			*cpy_buf;
  t_history		*first;
  t_history		*last;
}			t_head;

void		print_history(t_history *history);
void		push_front_history(t_head *, char *);
void		free_history(t_history *);
void		history_up(char **str, int *pos,
			   t_head *history, int *);
void		history_down(char **str, int *pos,
			     t_head *history, int *);
#endif /* !_HISTORY_H_ */
