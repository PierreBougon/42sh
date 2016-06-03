/*
** var_env_dep.c for azd in /home/debrau_c/Documents/cours/PSU/save_var_env/srcs
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Tue May 31 14:24:01 2016 debrau_c
** Last update Sat Jun  4 00:34:11 2016 debrau_c
*/

int	var_env_copy_fin(char *new, char **str, int j, int m)
{
  while (str[0][j] != ' ' && str[0][j] != '"')
    j++;
  j++;
  while (str[0][j] != '\0')
    {
      new[m] = str[0][j];
      ++m;
      ++j;
    }
  new[m] = '\0';
  return (0);
}

int	var_env_place_k(char *env)
{
  int	k;

  k = 0;
  while (env[k] != '\0' && env[k] != '=')
    ++k;
  if (env[k] == '=')
    ++k;
  else
    return (-1);
  return (k);
}

int	var_env_place_j(char *new, char *str, int index)
{
  int	j;

  j = 0;
  while (str[j] != '\0' && j < index)
    {
      new[j] = str[j];
      j = j + 1;
    }
  return (j);
}
