/*
** check_type_next.c for check_type_next.c in /home/gottin_o/Projets/lexer
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Mon May 19 14:39:39 2014 gottin_o
** Last update Thu May 29 17:40:29 2014 gottin_o
*/

#include <stdlib.h>
#include <string.h>
#include "lexer.h"

int	is_a_red(char *str, char **env)
{
  int	i;

  i = 0;
  (void) env;
  while (sepa_tab[i].sepa != NULL)
    {
      if (i >= 4 && i <= 7)
        {
          if (strcmp(sepa_tab[i].sepa, str) == 0)
            return (RED);
        }
      ++i;
    }
  return (-1);
}

int	is_a_semicolon(char *str, char **env)
{
  (void) env;
  if (strcmp(str, ";") == 0)
    return (SMC);
  return (-1);
}

int	is_other(char *str, char **env)
{
  (void) str;
  (void) env;
  return (OTH);
}
