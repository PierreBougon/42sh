/*
** my_getnbr.c for my_getnbr in /home/marel_m/rendu/EvalXpr
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Oct 14 14:50:44 2015 maud marel
** Last update Sat Mar  5 15:32:46 2016 maud marel
*/

int	my_getnbr(char *str)
{
  int   i;
  int   result;
  int	p;

  i = 0;
  p = 1;
  result = 0;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
        p = p * (-1);
      i = i + 1;
    }
  while (str[i] != '\0' && str[i] < 58 && str[i] > 47)
    {
      result = result * 10 + (str[i] - 48);
      i = i + 1;
    }
  if (result >= 2147483647)
    return (0);
  return (result * p);
}
