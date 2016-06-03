/*
** my_glob.h for azd in /home/debrau_c/Documents/cours/PSU/glob_easy
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Thu May 26 21:06:05 2016 debrau_c
** Last update Fri Jun  3 22:30:20 2016 debrau_c
*/

#ifndef MY_GLOB_H
# define MY_GLOB_H

# include <glob.h>

int	globing(char **str);
int	glob_strclen(char *str, char c);
int	glob_count_occur(char *str, char c);
char	*glob_strcdup(char *str, char c);
char	*glob_realloc(char *str, int size);
int	glob_strlen(char *str);
void	glob_strcat(char *dest, char *src);
void	glob_epur(char*str);
void	glob_clean_tab(char **recup);
int	glob_maj_quotes(int on_quotes, char c);
void	glob_clean_str_first(char *str);
char	**glob_str_tab(char *str);
void	glob_suppr_char(char *str, int index);

#endif /* !MY_GLOB_H */
