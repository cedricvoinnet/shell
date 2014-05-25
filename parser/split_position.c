/*
** split_position.c for split_position.c in /home/gottin_o/Projets/42sh/parser
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Fri May 23 19:01:43 2014 gottin_o
** Last update Sat May 24 20:07:25 2014 gottin_o
*/

#include <stdlib.h>
#include <string.h>
#include "my_tree.h"

int	split_next(char *str, int *priority, int i)
{
  int	position;
  int	index;

  index = 0;
  position = -1;
  while (sepa_tab[index].sepa != NULL)
    {
      if (strncmp(str, sepa_tab[index].sepa, sepa_tab[index].size) == 0)
        {
          if (sepa_tab[index].priority <= *priority)
            {
              position = i;
              *priority = sepa_tab[index].priority;
              return (position);
            }
        }
      ++index;
    }
  return (position);
}

int	get_sepa_infos(char *str, int position,
		       int *separator_size, int *separator_id)
{
  int	index;
  int	i;

  *separator_size = 0;
  *separator_id = 0;
  index = 0;
  i = 0;
  while (i != position)
    {
      ++str;
      ++i;
    }
  while (strncmp(str, sepa_tab[index].sepa, sepa_tab[index].size) != 0)
    ++index;
  *separator_size = sepa_tab[index].size;
  *separator_id = index;
  return (0);
}

int	split_position(char *str)
{
  int	i;
  int	tmp;
  int	position;
  int	priority;

  i = 0;
  priority = 6;
  position = -1;
  while (*str)
    {
      if ((tmp = split_next(str, &priority, i)) != -1)
        position = tmp;
      if (str[1] == str[0])
        {
          ++str;
          ++i;
        }
      ++str;
      ++i;
    }
  return (position);
}
