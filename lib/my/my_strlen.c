/*
** my_strlen.c for my_strlen in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue May 17 10:12:36 2016 marel_m
** Last update Tue May 17 10:13:03 2016 marel_m
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str)
    i++;
  return (i);
}
