/*
** sepa_func.c for sepa_func.c in /home/voinne_c/rendu/42sh/tree
** 
** Made by voinne_c
** Login   <voinne_c@epitech.net>
** 
** Started on  Mon May 12 21:55:19 2014 voinne_c
** Last update Fri May 30 15:24:42 2014 gottin_o
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_tree.h"

t_globalinfos	*semicolon(t_node *node, int *fd, t_globalinfos *info)
{
  if ((info = exec(node->left, fd, info)) ==  NULL)
    return (NULL);
  if (info->exit_now == 1)
    return (info);
  if (node->right->separator_id != NO_SEP || node->right->command[0] != 0)
    {
      if ((info = exec(node->right, fd, info)) == NULL)
	return (NULL);
    }
  return (info);
}

t_globalinfos	*func_or(t_node *node, int *fd, t_globalinfos *info)
{
  if ((info = exec(node->left, fd, info)) == NULL)
    return (NULL);
  if (info->exec_status == 0 || info->exit_now == 1)
    return (info);
  else
    {
      if ((info = exec(node->right, fd, info)) == NULL)
	return (NULL);
    }
  return (info);
}

t_globalinfos	*func_and(t_node *node, int *fd, t_globalinfos *info)
{
  if ((info = exec(node->left, fd, info)) == NULL)
    return (NULL);
  if (info->exec_status != 0 || info->exit_now == 1)
    return (info);
  if ((info = exec(node->right, fd, info)) == NULL)
    return (NULL);
  return (info);
}

t_globalinfos	*pipe2(t_node *node, t_globalinfos * info, int *fd, int *pipefd)
{
  int		pid;
  int		status;

  dup2(1, pipefd[1]);
  if ((pid = fork()) == -1)
    return (NULL);
  if (pid == 0)
    {
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      info = exec(node->right, fd, info);
      exit(0);
    }
  else
    {
      close(pipefd[0]);
      waitpid(pid, &status, 0);
    }
  return (info);
}

t_globalinfos	*func_pipe(t_node *node, int *fd, t_globalinfos *info)
{
  int		pipefd[2];
  int		pid;
  int		status;

  if (pipe(pipefd) == -1)
    return (NULL);
  if ((pid = fork()) == -1)
    return (NULL);
  if (pid == 0)
    {
      close(pipefd[0]);
      dup2(pipefd[1], 1);
      info = exec(node->left, fd, info);
      exit(0);
    }
  else
    {
      close(pipefd[1]);
      if (pipe2(node, info, fd, pipefd) == NULL)
	return (NULL);
      waitpid(pid, &status, 0);
    }
  return (info);
}
