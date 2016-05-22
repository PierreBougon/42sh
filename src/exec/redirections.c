/*
** redirections.c for redirections in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri May 20 13:59:36 2016 marel_m
** Last update Fri May 20 15:24:39 2016 marel_m
*/

int	redirection_right(t_sh *sh)
{
  if ((sh->exec->fd = open(sh->exec->exec,
			   O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -&
      || (pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      if (dup2(sh->exec->
    }
}
