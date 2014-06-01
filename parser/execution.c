/*
** execution.c for execution.c in /home/gottin_o/Projets/42sh/parser
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Tue May 20 16:54:47 2014 gottin_o
** Last update Fri May 30 16:14:16 2014 gottin_o
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include "my_tree.h"

static const t_builtin	g_pars[]=
  {
    {"env", 3, &env_reader},
    {"exit", 4, &my_exit},
    {"setenv", 6, &my_setenv},
    {"unsetenv", 8, &my_unsetenv},
    {"echo", 4, &my_echo},
    {"cd", 2, &cd},
    {NULL, 0, NULL}
  };

char	*command_prepare(char *command, t_globalinfos *info)
{
  char	**path_tab;
  char	*command_with_path;
  int	i;

  i = 0;
  if (strncmp(command, "./", 2) == 0)
    command = command + 2;
  if (access(command, X_OK) == 0)
    return (strdup(command));
  if ((path_tab = add_path_to_command(command, info->env)) == NULL)
    return (NULL);
  while (path_tab[i] != NULL)
    {
      if (access(path_tab[i], X_OK) == 0)
	{
	  command_with_path = strdup(path_tab[i]);
	  my_free_tab(path_tab);
	  return (command_with_path);
	}
      ++i;
    }
  print_typo_error(command);
  my_free_tab(path_tab);
  return (NULL);
}

int	execute(char **wordtab, t_globalinfos *info)
{
  char	*command_with_path;

  command_with_path = command_prepare(wordtab[0], info);
  if (command_with_path == NULL)
    return (FAILURE);
  if (execve(command_with_path, wordtab, info->env) == -1)
    return (FAILURE);
  free(command_with_path);
  return (0);
}

int	is_builtin_exec(char **wordtab)
{
  int	i;

  i = 0;
  if (wordtab != NULL)
    {
      while (g_pars[i].builtin != NULL &&
	     strcmp(wordtab[0], g_pars[i].builtin) != 0)
	++i;
    }
  if (g_pars[i].builtin != NULL)
    return (i);
  return (-1);
}

t_globalinfos	*exe_fork(char **wordtab, t_globalinfos *info)
{
  int		pid;
  int		status;

  pid = fork();
  if (pid == -1)
    return (NULL);
  if (pid == 0)
    {
      if (execute(wordtab, info) == FAILURE)
	exit(FAILURE);
    }
  else
    {
      if (waitpid(pid, &status, WUNTRACED | WCONTINUED) == -1)
	return (NULL);
      if (WIFEXITED(status))
	info->exec_status = WEXITSTATUS(status);
    }
  return (info);
}

t_globalinfos	*exec_launch(char **wordtab, t_globalinfos *info)
{
  int		i;

  if ((i = is_builtin_exec(wordtab)) != -1)
    {
      info = g_pars[i].fptr(info, wordtab);
      if (info == NULL)
	return (NULL);
    }
  else
    {
      if ((info = exe_fork(wordtab, info)) == NULL)
	return (NULL);
    }
  return (info);
}
