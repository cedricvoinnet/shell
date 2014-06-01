/*
** 42sh.c for 42sh in /home/gottin_o/Projets/42sh
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Tue May  6 17:22:17 2014 gottin_o
** Last update Fri May 30 17:53:13 2014 gottin_o
*/

#include <stdlib.h>
#include "lexer/lexer.h"
#include "sh.h"

t_globalinfos	*shell(char *str, t_globalinfos *info)
{
  int		ret;

  if ((ret = lexer(str, info)) == -1)
    return (NULL);
  if (ret == 1)
    return (info);
  if ((info = my_tree(str, info)) == NULL)
    return (NULL);
  return (info);
}

int	reading_loop(t_globalinfos *info)
{
  char	*line;

  my_putstr(info->prompt);
  while ((line = get_next_line(0)) != NULL)
    {
      line = epur_str(line);
      if (*line != '\0')
	{
	  if ((info = shell(line, info)) == NULL)
	    return (-1);
	  if (info->exit_now == 1)
	    return (info->exit_value);
	}
      free(line);
      my_putstr(info->prompt);
    }
  finish(info);
  return (0);
}

int			main(int ac, char **av, char **env)
{
  t_globalinfos		*info;

  (void) ac;
  (void) av;
  if ((info = init(env)) == NULL)
    return (EXIT_FAIL);
  return (reading_loop(info));
}
