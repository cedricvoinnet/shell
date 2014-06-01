/*
** cd.c for minishell in /home/voinne_c/rendu/PSU_2013_minishell2
** 
** Made by voinne_c
** Login   <voinne_c@epitech.net>
** 
** Started on  Wed Feb 19 08:41:56 2014 voinne_c
** Last update Fri May 30 00:16:57 2014 gottin_o
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../sh.h"

char	*pass_folder(char *str)
{
  char	*folder;

  while (*str != '=')
    ++str;
  ++str;
  folder = strdup(str);
  return (folder);
}

t_globalinfos	*move_to_folder(t_globalinfos *info, char *folder)
{
  int		ret;

  ret = chdir(folder);
  if (ret == -1)
    {
      printf("42sh: cd: %s: No such file or directory.\n", folder);
      info->exec_status = 1;
      return (info);
    }
  if ((info = get_old(info)) == NULL)
    return (NULL);
  info->exec_status = 0;
  return (info);
}

t_globalinfos	*return_to_home(t_globalinfos *info)
{
  int		index;
  char		*folder;

  index = locate_var(info->env, "HOME=");
  if (index == -1)
    {
      printf("42sh: cd: HOME not set\n");
      info->exec_status = 1;
      return (info);
    }
  folder = pass_folder(info->env[index]);
  if (chdir(folder) == -1)
    {
      printf("42sh: cd: %s: No such file or directory.\n", folder);
      info->exec_status = 1;
      return (info);
    }
  if ((info = get_old(info)) == NULL)
    return (NULL);
  info->exec_status = 0;
  return (info);
}

t_globalinfos	*move_to_last(t_globalinfos *info)
{
  int		index;
  char		*folder;

  index = locate_var(info->env, "OLDPWD=");
  if (index == -1)
    {
      printf("42sh: cd: OLDPWD not set\n");
      info->exec_status = 1;
      return (info);
    }
  folder = pass_folder(info->env[index]);
  if (chdir(folder) == -1)
    {
      printf("42sh: cd: %s: No such file or directory.\n", folder);
      info->exec_status = 1;
      return (info);
    }
  printf("%s\n", folder);
  if ((info = get_old(info)) == NULL)
    return (NULL);
  info->exec_status = 0;
  return (info);
}

t_globalinfos	*cd(t_globalinfos *info, char **str_tab)
{
  if (str_tab[1] == NULL || strcmp(str_tab[1], "--") == 0)
    {
      if ((info = return_to_home(info)) == NULL)
	return (NULL);
    }
  else if (str_tab[1])
    {
      if (strcmp(str_tab[1], "-") == 0)
	{
	  if ((info = move_to_last(info)) == NULL)
	    return (NULL);
	}
      else
	{
	  if ((info = move_to_folder(info, str_tab[1])) == NULL)
	    return (NULL);
	}
    }
  if ((info = get_pwd(info)) == NULL)
    return (NULL);
  info->exec_status = 0;
  return (info);
}
