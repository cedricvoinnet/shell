/*
** locate_var.c for locate_var.c in /home/gottin_o/Projets/49sh/tools
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Sun May 11 16:19:18 2014 gottin_o
** Last update Sat May 24 13:59:06 2014 gottin_o
*/

#include <string.h>
#include <stdlib.h>

int	locate_var(char **env, char *var_name)
{
  int	i;

  i = 0;
  if (env == NULL)
    return (-1);
 while (env[i] && strncmp(env[i], var_name, strlen(var_name)) != 0)
   ++i;
  if (env[i] == NULL)
    return (-1);
  else
    return (i);
}
