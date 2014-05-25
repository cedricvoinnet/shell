/*
** free_parser.c for 42sh in /home/voinne_c/rendu/42sh/42sh
** 
** Made by voinne_c
** Login   <voinne_c@epitech.net>
** 
** Started on  Fri May 23 10:17:24 2014 voinne_c
** Last update Fri May 23 13:16:39 2014 gottin_o
*/

#include <stdlib.h>
#include "../parser/my_tree.h"

void	free_tree(t_node *node)
{
  if (node->left == NULL)
    {
      free(node->command);
      free(node);
      node = NULL;
      return;
    }
  free_tree(node->left);
  free_tree(node->right);
  free(node);
  node = NULL;
}
