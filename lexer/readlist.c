/*
** readlist.c for read_list.c in /home/gottin_o/Projets/49sh/lexer
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Mon May 19 15:36:41 2014 gottin_o
** Last update Sat May 24 20:08:00 2014 gottin_o
*/

#include <stdlib.h>
#include <stdio.h>
#include "../lexer/lexer.h"

void	readlist(t_instructions *list)
{
  while (list != NULL)
    {
      printf("%s from type %d\n", list->instruction, list->type);
      list = list->next;
    }
}
