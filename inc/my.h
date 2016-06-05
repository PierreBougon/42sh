/*
** my.h for my in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_tetris/lib/my
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 18 14:26:59 2016
** Last update Sun Jun  5 11:02:43 2016 bougon_p
*/

#ifndef MY_H_
# define MY_H_

typedef	struct	s_tab
{
  int		nb;
  int		size;
}		t_tab;

int	my_strlen(char *);
char	*my_strcpy(char *, char *);
void	my_putchar(char);
void	my_putchar_error(char);
void	my_putstr(char *);
char	*my_realloc(char *, int);
char	*my_strdup(char *);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
int	my_put_nbr(int);
void	my_putstr(char *);
void	my_putstr_error(char *);
char	*my_strcpy(char *, char *);
void	my_show_tab_fd(char **, int);

#endif /* !MY_H_ */
