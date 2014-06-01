/*
** unsetenv.c for unsetenv.c in /home/gottin_o/Projets/49sh/builtins
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Thu May 15 11:17:14 2014 gottin_o
** Last update Fri May 30 00:08:36 2014 gottin_o
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../sh.h"

char	**my_delete_env_var(char **env, int pos)
{
  char	**new_tab;
  int	i;
  int	j;

  i = 0;
  j = 0;
  new_tab = malloc(sizeof(char *) * table_sizer(env));
  if (new_tab == NULL)
    return (NULL);
  while (env[i] != NULL)
    {
      if (i == pos)
        ++i;
      if (env[i] == NULL)
        {
          new_tab[j] = NULL;
          my_free_tab(env);
          return (new_tab);
        }
      new_tab[j++] = strdup(env[i++]);
    }
  new_tab[j] = NULL;
  my_free_tab(env);
  return (new_tab);
}

t_globalinfos	*my_unsetenv(t_globalinfos *info, char **command_wt)
{
  char		*var_name;
  int		i;

  i = 0;
  if (command_wt[1] == NULL)
    {
      printf("Usage: unsetenv [VAR_NAME]\n");
      info->exec_status = 1;
      return (info);
    }
  var_name = put_char_end(command_wt[1], '=');
  i = locate_var(info->env, var_name);
  if (i == -1)
    {
      printf("Unable to find the variable : %s\n", command_wt[1]);
      info->exec_status = 1;
      return (info);
    }
  if ((info->env = my_delete_env_var(info->env, i)) == NULL)
    return (NULL);
  info->exec_status = 0;
  return (info);
}
