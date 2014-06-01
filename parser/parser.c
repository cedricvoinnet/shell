/*
** my_tree.c for my_tree.c in /home/gottin_o/Projets/tree
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Mon May 12 19:47:07 2014 gottin_o
** Last update Sun Jun  1 14:00:56 2014 voinne_c
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "my_tree.h"

t_node		*new_node(char *command)
{
  t_node	*node;

  node = malloc(sizeof(*node));
  if (node == NULL)
    return (NULL);
  node->left = NULL;
  node->right = NULL;
  if ((node->command = strdup(command)) == NULL)
    return (NULL);
  node->separator_id = NO_SEP;
  return (node);
}

t_node		*create_tree(t_node *node)
{
  char		**split;
  int		separator_id;
  int		separator_size;
  int		where_to_split;

  where_to_split = split_position(node->command);
  if (where_to_split == -1)
    return (node);
  get_sepa_infos(node->command, where_to_split,
		 &separator_size, &separator_id);
  split = line_splitter(node->command,
			where_to_split, separator_size);
  if (split == NULL)
    return (NULL);
  node->command = NULL;
  node->separator_id = separator_id;
  node->left = new_node(split[0]);
  create_tree(node->left);
  node->right = new_node(split[1]);
  create_tree(node->right);
  my_free_tab(split);
  return (node);
}

t_globalinfos	*exec(t_node *node, int *fd, t_globalinfos *info)
{
  t_globalinfos	*(*tab[8])(t_node *, int *, t_globalinfos *);
  char		**wordtab;

  init_func(tab);
  if (info == NULL)
    return (NULL);
  if (node->left == NULL)
    {
      if ((wordtab = my_str_to_wordtab(node->command)) == NULL)
	return (NULL);
      if ((info = exec_launch(wordtab, info)) == NULL)
	return (NULL);
      my_free_tab(wordtab);
      return (info);
    }
  else
    return ((*tab[node->separator_id])(node, fd, info));
}

t_globalinfos	*my_tree(char *command, t_globalinfos *info)
{
  t_node	*node;
  int		fd[2];

  fd[0] = dup(0);
  fd[1] = dup(1);
  node = new_node(command);
  if (node == NULL)
    return (NULL);
  if ((node = create_tree(node)) == NULL)
    return (NULL);
  if ((info = exec(node, fd, info)) == NULL)
    return (NULL);
  free_tree(node);
  return (info);
}
