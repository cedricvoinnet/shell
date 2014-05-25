/*
** init.c for init.c in /home/gottin_o/Projets/42sh/init
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Wed Apr 30 15:30:56 2014 gottin_o
** Last update Sat May 24 19:55:42 2014 gottin_o
*/

#include <stdlib.h>
#include "../sh.h"

t_globalinfos	*init(char **env)
{
  t_globalinfos	*info;
  char		**envir;

  my_signal();
  info = malloc(sizeof(*info));
  if (info == NULL)
    return (NULL);
  if ((envir = extract_env(env)) == NULL)
    return (NULL);
  info->env = envir;
  if ((info->prompt = get_prompt(env)) == NULL)
    return (NULL);
  if ((info = get_pwd(info)) == NULL)
    return (NULL);
  info->exit_now = 0;
  return (info);
}
