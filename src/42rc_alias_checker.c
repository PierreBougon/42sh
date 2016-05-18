/*
** 42rc_alias_checker.c for check alias in /home/peau_c/rendu/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Wed May 18 12:37:44 2016 Poc
** Last update Wed May 18 13:57:44 2016 Poc
*/

#include <unistd.h>
#include "42s.h"

int	change_word(char **str, t_aliases *node, int pos, int end)
{
  char	*corrected_chain;
  int	i;
  int	j;

  j = 0;
  i = 0;
  printf("%s\n", *str);
  if ((corrected_chain =
       malloc(sizeof(char) * (strlen(*str) + strlen(node->original) + 1))) == NULL)
    return (1);

  return (0);
}

int	check_alias(t_aliases *head, char **str)
{
  int	i;

  while (head)
    {
      i = 0;
      while ((*str)[i])
	{
	  if (i == 0 || (*str)[i] == ' ')
	    if (strcmp((*str) + (i == 0 ? i : i + 1), head->original) == 0)
	      {
		if (change_word(str, head,
				(i == 0 ? i : i + 1), i + strlen(head->original)))
		  return (1);
		printf("i zink i now this\n");
	      }
	  i++;
	}
      head = head->next;
    }
  return (0);
}
