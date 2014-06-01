/*
** assign_types.c for check_syntax.c in /home/gottin_o/Projets/lexer
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Fri May 16 23:51:23 2014 gottin_o
** Last update Thu May 29 18:16:10 2014 gottin_o
*/

#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

void	assign_types(t_instructions *list, char **env)
{
  while (list != NULL)
    {
      list->type = check_type(list->instruction, env);
      list = list->next;
    }
}

int	check_compatibility(int type1, int type2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (syntax_tab[i].type != type1)
    ++i;
  while (syntax_tab[i].followed_by[j] != END)
    {
      if (syntax_tab[i].followed_by[j] == type2)
	return (1);
      ++j;
    }
  return (-1);
}

int	check_syntax(t_instructions *list)
{
  if (list->type != OTH && list->type != RED)
    return (print_unexp_token(list->instruction));
  while (list->next != NULL)
    {
      if (check_compatibility(list->type, list->next->type) == -1)
	return (print_unexp_token(list->next->instruction));
      list = list->next;
    }
  if (list->type != OTH && list->type != SMC)
    {
      if (list->type == RED)
	return (print_newline_error());
      return (print_unexp_token(list->instruction));
    }
  return (0);
}
