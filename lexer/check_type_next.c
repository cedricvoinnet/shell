/*
** check_type_next.c for check_type_next.c in /home/gottin_o/Projets/lexer
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Mon May 19 14:39:39 2014 gottin_o
** Last update Sun May 25 15:05:57 2014 gottin_o
*/

#include <stdlib.h>
#include <string.h>
#include "lexer.h"

int	is_a_left_red(char *str, char **env)
{
  int	i;

  i = 0;
  (void) env;
  while (sepa_tab[i].sepa != NULL)
    {
      if (i == 4 || i == 6)
        {
          if (strcmp(sepa_tab[i].sepa, str) == 0)
            return (LRED);
        }
      ++i;
    }
  return (-1);
}

int	is_a_right_red(char *str, char **env)
{
  int	i;

  i = 0;
  (void) env;
  while (sepa_tab[i].sepa != NULL)
    {
      if (i == 5 || i == 7)
        {
          if (strcmp(sepa_tab[i].sepa, str) == 0)
            return (RRED);
        }
      ++i;
    }
  return (-1);
}

int	is_a_arg(char *str, char **env)
{
  (void) str;
  (void) env;
  return (ARG);
}

int	is_a_semicolon(char *str, char **env)
{
  (void) env;
  if (strcmp(str, ";") == 0)
    return (SMC);
  return (-1);
}
