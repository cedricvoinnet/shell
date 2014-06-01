/*
** check_type.c for check_type.c in /home/gottin_o/Projets/lexer
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Fri May 16 17:27:36 2014 gottin_o
** Last update Thu May 29 17:43:06 2014 gottin_o
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "lexer.h"

int	is_a_file(char *str, char **env)
{
  (void) env;
  if (access(str, F_OK) == 0)
    return (1);
  if (check_dir(str) == 1)
    return (1);
  return (-1);
}

int	is_a_exe(char *str, char **env)
{
  int	i;
  char	**exe_with_path;

  i = 0;
  if (check_dir(str) == 1)
    return (-1);
  if (strncmp(str, "./", 2) == 0)
    str = str + 2;
  if (access(str, X_OK) == 0)
    return (1);
  exe_with_path = add_path_to_command(str, env);
  if (exe_with_path == NULL)
    return (-1);
  while (exe_with_path[i])
    {
      if (access(exe_with_path[i], X_OK) == 0)
	{
	  my_free_tab(exe_with_path);
	  return (1);
	}
      ++i;
    }
  if (exe_with_path[i] == NULL)
    my_free_tab(exe_with_path);
  return (-1);
}

int	is_a_sep(char *str, char **env)
{
  int	i;

  i = 0;
  (void) env;
  while (sepa_tab[i].sepa != NULL)
    {
      if (sepa_tab[i].priority == 2 || sepa_tab[i].priority == 3)
	{
	  if (strcmp(sepa_tab[i].sepa, str) == 0)
	    return (SEP);
	}
      ++i;
    }
  return (-1);
}

int	check_type(char *str, char **env)
{
  int	i;
  int	(*check_tab[8])(char *str, char **env);
  int	value;

  i = 0;
  init_check_tab(check_tab);
  while (i != 8)
    {
      value = (*check_tab[i])(str, env);
      if (value != -1)
	return (value);
      ++i;
    }
  return (-1);
}
