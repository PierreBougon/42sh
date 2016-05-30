/*
** display_echo.c for display in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 29 18:40:38 2016 bougon_p
** Last update Mon May 30 18:57:55 2016 bougon_p
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

void	print_help()
{
  printf("\necho : Usage : echo [OPTION] [STRINGS]\n\n");
  printf("-n \t\tDo not output the trailing newline\n");
  printf("-e \t\tEnable interpretation of backslash escapes\n");
  printf("-E \t\tDisable interpretation of backslash escapes (default)\n");
  printf("--help \t\tDisplay this help and exit\n");
  printf("--version \tOutput version information and exit\n");
}

void	invert(bool *waiting_d, bool *waiting_s, char c)
{
  if (c == '"')
    {
      if (!*waiting_d)
        *waiting_d = true;
      else
        *waiting_d = false;
    }
  else if (c == '\'')
    {
      if (!*waiting_s)
        *waiting_s = true;
      else
        *waiting_s = false;
    }
}

void	print_str_no_change(char *str)
{
  int	i;
  bool	waiting_s;
  bool	waiting_d;

  i = -1;
  waiting_s = false;
  waiting_d = false;
  while (str[++i])
    {
      if (str[i] != '"' && str[i] != '\'')
        printf("%c", str[i]);
      else
        invert(&waiting_d, &waiting_s, str[i]);
    }
  fflush(stdout);
}

int	convert_next_letter(char c, t_echo *opt)
{
  int	i;

  i = -1;
  while (++i < NB_SPE_ECHO && opt->sequence[i] != c);
  if (i >= NB_SPE_ECHO)
    return (0);
  opt->ftab[i]();
  if (i == 3)
    return (2);
  else if (i == 10)
    return (3);
  else if (i == 11)
    return (4);
  return (0);
}

void	init_tab(t_echo *opt)
{
  opt->ftab[0] = print_backslash;
  opt->ftab[1] = print_alert;
  opt->ftab[2] = print_backspace;
  opt->ftab[3] = print_nomore;
  opt->ftab[4] = print_escape;
  opt->ftab[5] = print_formfeed;
  opt->ftab[6] = print_newline;
  opt->ftab[7] = print_carriageret;
  opt->ftab[8] = print_tab;
  opt->ftab[9] = print_verttab;
  opt->ftab[10] = print_octal;
  opt->ftab[11] = print_hexa;
  opt->ftab[12] = print_squote;
  opt->ftab[13] = print_dquote;
  opt->sequence[0] = '\\';
  opt->sequence[1] = 'a';
  opt->sequence[2] = 'b';
  opt->sequence[3] = 'c';
  opt->sequence[4] = 'e';
  opt->sequence[5] = 'f';
  opt->sequence[6] = 'n';
  opt->sequence[7] = 'r';
  opt->sequence[8] = 't';
  opt->sequence[9] = 'v';
  opt->sequence[10] = '0';
  opt->sequence[11] = 'x';
  opt->sequence[12] = '\'';
  opt->sequence[13] = '\"';
}

void	print_str_changed(char *str, t_echo *opt)
{
  int	i;
  bool	waiting_s;
  bool	waiting_d;
  int	ret;

  i = -1;
  waiting_s = false;
  waiting_d = false;
  init_tab(opt);
  while (str[++i])
    {
      if (str[i] != '"' && str[i] != '\'' && str[i] != '\\')
        printf("%c", str[i]);
      else if (str[i] == '\\')
	{
	  if ((ret = convert_next_letter(str[++i], opt)) == 2)
	    {
	      fflush(stdout);
	      return ;
	    }
	  else if (ret == 3)
	    {
	      print_octal_char(&str[i]);
	    }
	  else if (ret == 4)
	    {
	      print_hexa_char(&str[i]);
	    }
	}
      else
        invert(&waiting_d, &waiting_s, str[i]);
    }
  fflush(stdout);
}

void	print_echo(t_echo *opt, char **arg)
{
  int	i;

  i = -1;
  while (arg[++i])
    {
      if ((arg[i][0] == '-' && opt_exist(arg[i], opt))
          || arg[i][0] != '-')
        {
          if (opt->opt_E)
            {
              /* printf("%s", arg[i]); */
              /* fflush(stdout); */
              print_str_no_change(arg[i]);
            }
          else if (opt->opt_e)
            {
              /* write(1, arg[i], strlen(arg[i])); */
              /* fflush(stdout); */
              print_str_changed(arg[i], opt);
            }
        }
    }
  if (!opt->opt_n)
    write(1, "\n", 1);
}
