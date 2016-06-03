/*
** check_quote.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jun  3 20:47:08 2016 Mathieu Sauvau
** Last update Fri Jun  3 20:58:14 2016 Mathieu Sauvau
*/

int	auto_check_quote(char *str)
{
  int	i;
  int	quote_s;
  int	quote_d;

  i = -1;
  quote_s = 0;
  quote_d = 0;
  while (str[++i])
    {
      if (str[i] == '\'')
	++quote_s;
      if (str[i] == '"')
	++quote_d;
    }
  if (quote_s % 2 != 0 || quote_d % 2 != 0)
    return (0);
  return (1);
}
