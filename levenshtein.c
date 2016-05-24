/*
** levenshtein.c for distance search in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue May 24 14:58:26 2016 bougon_p
** Last update Tue May 24 15:56:03 2016 bougon_p
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	print_matrix(int **matrix, int width)
{
  int	i;
  int	j;

  j = -1;
  while (matrix[++j])
    {
      i = -1;
      while (++i <= width)
	{
	  printf("%d", matrix[j][i]);
	}
      printf("\n");
    }
}

int	minimum(int **matrix, int i, int j, int cost)
{
  int	a;
  int	b;
  int	c;

  a = 1 + matrix[i][j - 1];
  b = 1 + matrix[i - 1][j];
  c = cost + matrix[i - 1][j - 1];
  if (a < b && a < c)
    return (a);
  else if (b < a && b < c)
    return (b);
  else
    return (c);
}

int	**init_tab(int height, int width)
{
  int	i;
  int	**tab;

  if (!(tab = malloc(sizeof(int *) * (height + 2))))
    return (NULL);
  tab[height + 1] = NULL;
  i = -1;
  while (++i < height + 1)
    {
      if (!(tab[i] = malloc(sizeof(int) * (width + 2))))
	return (NULL);
    }
  return (tab);
}

int	levenshtein(char *str1, char *str2)
{
  int	i;
  int	j;
  int	cost;
  int	len1;
  int	len2;
  int	**matrix;

  len1 = strlen(str1);
  len2 = strlen(str2);
  if (!(matrix = init_tab(len1, len2)))
    return (-1);
  i = 0;
  while (++i <= len1)
    matrix[i][0] = i;
  j = 0;
  while (++j <= len2)
    matrix[0][j] = j;
  matrix[0][0] = 0;
  i = 0;
  while (++i <= len1)
    {
      j = 0;
      while (++j <= len2)
	{
	  cost = (str1[i - 1] == str2[j -1]) ? 0 : 1;
	  matrix[i][j] = minimum(matrix, i, j, cost);
	}
    }
  print_matrix(matrix, len2);
  return (matrix[len1 - 1][len2 - 1]);
}

int	main(int ac, char **av)
{
  int	dist;

  if (ac != 3)
    return (printf("Wrong usage\n"), 1);
  dist = levenshtein(av[1], av[2]);
  printf("Distance = %d\n", dist);
}
