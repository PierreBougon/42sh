/*
** my_putchar_error.c for my_putchar_error in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris/lib/my
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar  4 21:41:01 2016 maud marel
** Last update Fri Mar 18 14:31:20 2016 
*/

#include <unistd.h>
#include <stdlib.h>

void	my_putchar_error(char c)
{
  if (write(2, &c, 1) == -1)
    exit(1);
}
