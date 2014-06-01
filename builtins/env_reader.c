/*
** env_reader.c for env_reader.c in /home/gottin_o/Projets/42sh/env
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Tue Apr 29 19:47:05 2014 gottin_o
** Last update Fri May 30 00:04:51 2014 gottin_o
*/

#include <stdio.h>
#include <stdlib.h>
#include "../parser/my_tree.h"

t_globalinfos	*env_reader(t_globalinfos *info, char **tab)
{
  int		i;

  (void) tab;
  i = 0;
  if (info->env != NULL)
    {
      while (info->env[i])
	{
	  printf("%s\n", info->env[i]);
	  ++i;
	}
    }
  info->exec_status = 0;
  return (info);
}
