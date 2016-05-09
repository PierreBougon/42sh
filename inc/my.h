/*
** my.h for my in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_tetris/lib/my
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 18 14:26:59 2016
** Last update Wed Apr  6 18:30:38 2016 marel_m
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
void	my_putstr(char *);
char	*my_realloc(char *, int);
char	*my_strdup(char *);

#endif /* !MY_H_ */
