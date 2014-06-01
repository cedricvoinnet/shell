/*
** line_splitter.c for line_splitter.c in /home/gottin_o/Projets/tree
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Tue May 13 15:42:14 2014 gottin_o
** Last update Fri May 30 00:15:02 2014 gottin_o
*/

#include <stdlib.h>
#include <string.h>
#include "my_tree.h"

char	*get_left_part(char *str, int split_pos)
{
  char	*left;
  int	size;

  if (split_pos == 0)
    {
      if ((left = malloc(sizeof(char) * 2)) == NULL)
	return (NULL);
      left[0] = 0;
      left[1] = 0;
      return (left);
    }
  while (str[split_pos - 1] == ' ')
    --split_pos;
  size = split_pos + 1;
  left = malloc(sizeof(char) * size);
  if (left == NULL)
    return (NULL);
  strncpy(left, str, split_pos);
  left[size - 1] = '\0';
  return (left);
}

char	*get_right_part(char *str, int split_pos, int sepa_size)
{
  char	*right;
  int	size;
  int	i;
  int	j;

  i = split_pos + sepa_size;
  j = 0;
  size = strlen(str) - (split_pos + sepa_size);
  right = malloc(sizeof(char) * (size + 1));
  if (right == NULL)
    return (NULL);
  while (str[i] == ' ')
    ++i;
  while (str[i] != '\0')
    right[j++] = str[i++];
  right[j] = '\0';
  return (right);
}

char    **line_splitter(char *str, int where_to_split, int separator_size)
{
  char  **split;

  split = malloc(sizeof(char *) * 3);
  if (split == NULL)
    return (NULL);
  split[0] = get_left_part(str, where_to_split);
  split[1] = get_right_part(str, where_to_split, separator_size);
  split[2] = NULL;
  if (split[0] == NULL || split[1] == NULL)
    return (NULL);
  return (split);
}
