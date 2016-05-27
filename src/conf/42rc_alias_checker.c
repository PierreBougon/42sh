/*
** 42rc_alias_checker.c for check alias in /home/peau_c/rendu/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Wed May 18 12:37:44 2016 Poc
** Last update Fri May 27 16:36:01 2016 Poc
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

int	change_word(char **str, t_aliases *node, UNUSED int pos, UNUSED int end)
{
  char	*corrected_chain;
  char	*tmp;
  int	i;
  int	j;

  i = strlen(*str);
  printf("change word %s\npos = %d\nend %d\nlenght %d\n", *str, pos, end, strlen(*str));
  if ((corrected_chain =
       malloc(sizeof(char) * (strlen(*str) + strlen(node->alias) + 1))) == NULL)
     return (1);
  (*str)[pos] = 0;
  (*str)[end] = 0;
  printf("%d %d\n", pos, end);
  strcpy(corrected_chain, *str);
  strcat(corrected_chain, node->alias);
  strcat(corrected_chain, (*str) + end + (end == i ? 0 : 1));
  *str = corrected_chain;
  printf("%s\n", corrected_chain);
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
	    {
	      if (strncmp((*str) + (i == 0 ? i : i + 1),
			  head->original, strlen(head->original)) == 0)
	      {
		printf("i zink i now this\n");
		if (change_word(str, head,
				(i == 0 ? i : i + 1), i + strlen(head->original)))
		  return (1);
	      }
	    }
	  i++;
	}
      head = head->next;
    }
  return (0);
}
