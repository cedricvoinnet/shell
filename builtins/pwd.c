/*
** pwd.c for 42sh in /home/gazzol_j/rendu/42deuch
** 
** Made by a
** Login   <gazzol_j@epitech.net>
** 
** Started on  Mon May 19 14:31:38 2014 a
** Last update Sat May 24 17:39:56 2014 gottin_o
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../parser/my_tree.h"
#include "../sh.h"

t_globalinfos	*get_pwd(t_globalinfos *info)
{
  char		**setpwd;
  char		*pwd;

  if ((setpwd = malloc(sizeof(char *) * 3)) == NULL)
    return (NULL);
  if ((pwd = malloc(sizeof(char) * 1024)) == NULL)
    return( NULL);
  if ((pwd = getcwd(pwd, 1024)) == NULL)
    return (NULL);
  setpwd[0] = strdup("setenv");
  setpwd[1] = strdup("PWD");
  setpwd[2] = strdup(pwd);
  if ((info = my_setenv(info, setpwd)) == NULL)
    return (NULL);
  return (info);
}

t_globalinfos	*get_old(t_globalinfos *info)
{
  char		**setold;
  char		*oldpwd;
  int		i;

  i = locate_var(info->env, "PWD=");
  setold = malloc(sizeof(char *) * 3);
  if (setold == NULL)
    return (NULL);
  setold[0] = strdup("setenv");
  setold[1] = strdup("OLDPWD");
  oldpwd = pass_folder(info->env[i]);
  setold[2] = strdup(oldpwd);
  if ((info = my_setenv(info, setold)) == NULL)
    return (NULL);
  return (info);
}
