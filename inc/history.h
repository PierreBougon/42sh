/*
** history.h for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri May 13 17:37:35 2016 Mathieu Sauvau
// Last update Mon May 30 11:50:19 2016 Mathieu Sauvau
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
