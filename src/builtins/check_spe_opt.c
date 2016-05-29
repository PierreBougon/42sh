/*
** check_spe_opt.c for opt in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 29 18:43:45 2016 bougon_p
** Last update Sun May 29 18:44:19 2016 bougon_p
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

bool	version(char *str)
{
  if (strcmp(str, "-version") == 0)
    return (true);
  return (false);
}

bool	help(char *str)
{
  if (strcmp(str, "-help") == 0)
    return (true);
  return (false);
}
