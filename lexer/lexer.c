/*
** lexer.c for lexer.c in /home/gottin_o/Projets/lexer
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Fri May 16 23:14:54 2014 gottin_o
** Last update Thu May 29 22:41:29 2014 gottin_o
*/

#include <stdlib.h>
#include "lexer.h"
#include "../sh.h"

int			lexer(char *str, t_globalinfos *info)
{
  t_instructions        *list;

  if ((list = copy_in_list(str)) == NULL)
    return (-1);
  assign_types(list, info->env);
  if (check_syntax(list) == -1)
    return (1);
  free_list(&list);
  return (0);
}
