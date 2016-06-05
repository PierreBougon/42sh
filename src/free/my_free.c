/*
** my_free.c for free in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Sat Jun  4 19:19:16 2016 marel_m
** Last update Sat Jun  4 20:07:59 2016 marel_m
*/

#include <stdlib.h>

void	my_free(void **str)
{
  if (*str != NULL)
    free(*str);
  *str = NULL;
}
