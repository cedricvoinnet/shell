/*
** free_list.c for free_list.c in /home/gottin_o/Projets/lexer
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Mon May 19 14:20:21 2014 gottin_o
** Last update Mon May 19 15:22:51 2014 gottin_o
*/

#include <stdlib.h>
#include "../lexer/lexer.h"

void			free_list(t_instructions **list)
{
  t_instructions	*tmp;

  while ((*list)->next != NULL)
    {
      tmp = *list;
      *list = (*list)->next;
      free(tmp->instruction);
      free(tmp);
    }
  free((*list));
  list = NULL;
}
