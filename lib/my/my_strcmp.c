/*
** my_strcmp.c for my_strcmp in /home/marel_m/rendu/Piscine_C_J06/ex_06
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Oct  5 21:57:02 2015 maud marel
** Last update Thu Mar  3 10:50:54 2016 maud marel
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	tot;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != 0) && (s2[i] != 0))
    i++;
  tot = s1[i] - s2[i];
  return (tot);
}
