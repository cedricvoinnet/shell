/*
** sepa_func.c for sepa_func.c in /home/voinne_c/rendu/42sh/tree
** 
** Made by voinne_c
** Login   <voinne_c@epitech.net>
** 
** Started on  Mon May 12 21:55:19 2014 voinne_c
** Last update Sun May 25 14:45:19 2014 gottin_o
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_tree.h"

t_globalinfos	*l_db_redir(t_node *node, int *fd, t_globalinfos *info)
{
  int		file_descriptor;

  if ((file_descriptor = read_open_file(node->right->command)) == -1)
    return (NULL);
  dup2(file_descriptor, 0);
  exec(node->left, fd, info);
  dup2(fd[0], 0);
  close(file_descriptor);
  return (info);
}

t_globalinfos	*r_db_redir(t_node *node, int *fd, t_globalinfos *info)
{
  int		file_descriptor;

  if (create_if_not_exists(node->right->command) == -1 ||
      (file_descriptor = write_open_file
       (node->right->command, APPEND)) == -1)
    return (NULL);
  if (dup2(file_descriptor, 1) == -1)
    return (NULL);
  exec(node->left, fd, info);
  if (dup2(fd[1], 1) == -1)
    return (NULL);
  close(file_descriptor);
  return (info);
}

t_globalinfos	*r_redir(t_node *node, int *fd, t_globalinfos *info)
{  
  int		file_descriptor;

  if (create_if_not_exists(node->right->command) == -1 ||
      (file_descriptor = write_open_file
       (node->right->command, TRUNC)) == -1)
    return (NULL);
  if (dup2(file_descriptor, 1) == -1)
    return (NULL);
  exec(node->left, fd, info);
  if (dup2(fd[1], 1) == -1)
    return (NULL);
  close(file_descriptor);
  return (info);
}

t_globalinfos	*l_redir(t_node *node, int *fd, t_globalinfos *info)
{  
  int		file_descriptor;

  if ((file_descriptor = read_open_file(node->right->command)) == -1)
    return (NULL);
  dup2(file_descriptor, 0);
  exec(node->left, fd, info);
  dup2(fd[0], 0);
  close(file_descriptor);
  return (info);
}
