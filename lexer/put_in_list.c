/*
** put_in_list.c for put_in_list.c in /home/gottin_o/Projets/lexer
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Fri May 16 23:43:10 2014 gottin_o
** Last update Sun May 25 14:57:30 2014 gottin_o
*/

#include <stdlib.h>
#include <string.h>
#include "lexer.h"

int			put_in_list(t_instructions **list, char *instruction)
{
  t_instructions	*new;
  t_instructions	*last;

  if (*list)
    {
      if (!(new = malloc(sizeof(*new))))
	return (-1);
      new->instruction = instruction;
      last = (*list);
      while (last->next != NULL)
	last = last->next;
      new->next = last->next;
      last->next = new;
      return (0);
    }
  if (!(new = malloc(sizeof(*new))))
    return (-1);
  new->instruction = strdup(instruction);
  new->next = *list;
  *list = new;
  return (0);
}
