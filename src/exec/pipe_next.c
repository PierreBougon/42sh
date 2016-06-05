/*
** pipe.c for pipe in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Thu May 26 13:16:31 2016 marel_m
** Last update Sun Jun  5 15:08:22 2016 Poc
*/

#include <unistd.h>
#include "42s.h"

void	close_all_first_pipe(int **fd, int target)
{
  int	i;

  i = 1;
  while (fd[i])
    {
      if (i != target)
	{
	  close(fd[i][1]);
	  close(fd[i][0]);
	}
      i++;
    }
}
