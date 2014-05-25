/*
** extract_env.c for extract_env.c in /home/gottin_o/Projets/42sh/env
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Tue Apr 29 19:45:15 2014 gottin_o
** Last update Wed May 21 15:44:11 2014 gottin_o
*/

#include <stdlib.h>
#include <string.h>
#include "../sh.h"

void	env_size(int *size, char **envp)
{
  *size = 0;
  while (envp[*size])
    (*size)++;
}

char	**extract_env(char **envp)
{
  int	size;
  int	i;
  char	**env;

  i = 0;
  env_size(&size, envp);
  env = malloc(sizeof(char *) * (size + 1));
  if (env == NULL)
    return (NULL);
  while (i != size)
    {
      env[i] = strdup(envp[i]);
      ++i;
    }
  env[i] = NULL;
  return (env);
}
