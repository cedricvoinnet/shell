/*
** my_exit.c for my_exit.c in /home/gottin_o/Projets/42sh/builtins
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Tue May 20 17:48:56 2014 gottin_o
** Last update Sat May 24 15:39:55 2014 gottin_o
*/

#include <stdlib.h>
#include "../sh.h"

t_globalinfos	*my_exit(t_globalinfos *info, char **command_wt)
{
  int		return_value;

  if (command_wt[1])
    return_value = my_getnbr(command_wt[1]);
  else
    return_value = 0;
  info->exit_now = 1;
  info->exit_value = return_value;
  return (info);
}
