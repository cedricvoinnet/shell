/*
** setenv.c for setenv.c in /home/gottin_o/Projets/49sh/builtins
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Thu May 15 11:13:22 2014 gottin_o
** Last update Fri May 30 00:07:50 2014 gottin_o
*/

#include <string.h>
#include <stdlib.h>
#include "../sh.h"

int	table_sizer(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  return (i);
}

char	**my_add_env_var(char **env, char *var_name, char *var)
{
  char	**new_tab;
  int	size;
  int	i;

  i = 0;
  size = strlen(var_name) + strlen(var) + 1;
  new_tab = malloc(sizeof(char *) * (table_sizer(env) + 2));
  if (new_tab == NULL)
    return (NULL);
  new_tab[0] = malloc(sizeof(char) * size);
  if (new_tab[0] == NULL)
    return (NULL);
  strcpy(new_tab[0], var_name);
  strcat(new_tab[0], var);
  while (env[i] != NULL)
    {
      new_tab[i + 1] = strdup(env[i]);
      ++i;
    }
  new_tab[i + 1] = NULL;
  my_free_tab(env);
  return (new_tab);
}

char	**my_var_overwrite(char **env, char *var_name, char *var, int pos)
{
  int	size;

  size = strlen(var_name) + strlen(var) + 1;
  free(env[pos]);
  env[pos] = malloc(sizeof(char) * size);
  if (env[pos] == NULL)
    return (NULL);
  strcpy(env[pos], var_name);
  strcat(env[pos], var);
  return (env);
}

t_globalinfos	*my_setenv(t_globalinfos *info, char **command_wt)
{
  char		*var_name;
  int		i;

  i = 0;
  if (command_wt[1] == NULL || command_wt[2] == NULL)
    {
      my_putstr("Usage: setenv [VAR_NAME] [CONTENT]\n");
      info->exec_status = 1;
      return (info);
    }
  var_name = put_char_end(command_wt[1], '=');
  if (var_name == NULL)
    return (NULL);
  i = locate_var(info->env, var_name);
  if (i == -1)
    {
      if ((info->env = my_add_env_var
	   (info->env, var_name, command_wt[2])) == NULL)
	return (NULL);
    }
  else
    my_var_overwrite(info->env, var_name, command_wt[2], i);
  info->exec_status = 0;
  return (info);
}
