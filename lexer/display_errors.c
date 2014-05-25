/*
** display_errors.c for display_errors.c in /home/gottin_o/Projets/42sh/lexer
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Mon May 19 20:19:20 2014 gottin_o
** Last update Mon May 19 20:26:18 2014 gottin_o
*/

#include <stdio.h>

int	print_typo_error(char *name)
{
  printf("If '%s' is not a typo, you can use command-not-found"
         , name);
  printf(" to lookup the package that conatins it, like this:\n cnf %s\n"
         , name);
  return (-1);
}

int	print_no_such_file(char *name)
{
  printf("42sh: %s: No such file or directory\n", name);
  return (-1);
}

int	print_unexp_token(char *name)
{
  printf("42sh : syntax error near unexpected token '%s'\n", name);
  return (-1);
}
