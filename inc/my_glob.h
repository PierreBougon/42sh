/*
** my_glob.h for azd in /home/debrau_c/Documents/cours/PSU/glob_easy
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Thu May 26 21:06:05 2016 debrau_c
** Last update Sun May 29 18:00:18 2016 debrau_c
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

#endif /* !MY_GLOB_H */
