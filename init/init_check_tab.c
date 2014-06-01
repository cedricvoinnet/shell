/*
** init_check_tab.c for init_check_tab.c in /home/gottin_o/Projets/lexer
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Mon May 19 14:37:16 2014 gottin_o
** Last update Thu May 29 17:38:29 2014 gottin_o
*/

#include <stdlib.h>
#include "../lexer/lexer.h"

void	init_check_tab(int (*check_tab[])(char *, char **))
{
  check_tab[0] = &is_a_semicolon;
  check_tab[1] = &is_a_sep;
  check_tab[2] = &is_a_red;
  check_tab[3] = &is_other;
  check_tab[4] = NULL;
}
