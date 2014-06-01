/*
** echo.c for 42sh in /home/gazzol_j/rendu/42deuch
** 
** Made by a
** Login   <gazzol_j@epitech.net>
** 
** Started on  Tue May 20 18:04:53 2014 a
** Last update Fri May 30 00:06:21 2014 gottin_o
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../sh.h"

int	replace_doll(char *str, char **env)
{
  char	*value;
  int	i;

  ++str;
  i = locate_var(env, str);
  if (i == -1)
    {
      printf("Unable to find %s variable.\n", str);
      return (-1);
    }
  else
    {
      value = pass_folder(env[i]);
      my_putstr(value);
    }
  return (0);
}

int	n_option(char **command_wt)
{
  int	i;

  i = 0;
  while (command_wt[i] != NULL)
    {
      if (strcmp(command_wt[i], "-n") == 0)
	return (1);
      ++i;
    }
  return (-1);
}

int	echo_aff(char **command_wt, char **env)
{
  int	i;

  i = 1;
  while (command_wt[i + 1] != NULL)
    {
      if (command_wt[i][0] == '$')
	{
	  if ((replace_doll(command_wt[i], env)) == -1)
	    return (-1);
	}
      else
	my_putstr(command_wt[i]);
      my_putchar(' ');
      ++i;
    }
  if (command_wt[i][0] == '$')
    {
      if ((replace_doll(command_wt[i], env)) == -1)
	return (-1);
    }
  else
    my_putstr(command_wt[i]);
  return (0);
}

t_globalinfos	*my_echo(t_globalinfos *info, char **command_wt)
{
  if (command_wt[1] == NULL)
    {
      my_putchar('\n');
      info->exec_status = 0;
      return (info);
    }
  if (echo_aff(command_wt, info->env) == -1)
    {
      info->exec_status = 1;
      return (info);
    }
  if (n_option(command_wt) != 1)
    my_putchar('\n');
  info->exec_status = 0;
  return (info);
}
