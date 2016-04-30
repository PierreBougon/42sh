/*
** my_strlen.c for strlen in /home/peau_c/rendu/PSU_2015_42sh/src
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Apr 30 22:22:33 2016 Poc
** Last update Sat Apr 30 22:23:17 2016 Poc
*/

int	my_strlen(char *str)
{
  char	*tmp;

  if (!str)
    return (0);
  tmp = str;
  while (str[0])
    str++;
  return (tmp - str);
}
