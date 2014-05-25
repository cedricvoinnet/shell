/*
** assign_types.c for check_syntax.c in /home/gottin_o/Projets/lexer
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Fri May 16 23:51:23 2014 gottin_o
** Last update Sat May 24 20:08:30 2014 gottin_o
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

int	gere_error(int type1, char *str, char *str2)
{
  if (type1 == SEP || type1 == SMC)
    print_typo_error(str2);
  else if (type1 == LRED || type1 == RRED)
    print_no_such_file(str2);
  else if (type1 == ARG || type1 == EXE || type1 == FILE)
    print_unexp_token(str);
  return (-1);
}

int	check_syntax(t_instructions *list)
{
  if (list->type != EXE && list->type != BTN && list->type != ARG)
    return (print_unexp_token(list->instruction));
  else if (list->type == ARG)
    return (print_typo_error(list->instruction));
  while (list->next != NULL)
    {
      if (check_compatibility(list->type, list->next->type) == -1)
	return (gere_error(list->type, list->instruction,
			   list->next->instruction));
      list = list->next;
    }
  if (list->type == SEP || list->type == LRED || list->type == RRED)
    return (print_unexp_token(list->instruction));
  return (0);
}
