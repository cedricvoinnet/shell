/*
** finish.c for finish.c in /home/gottin_o/Projets/42sh
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Wed May 21 16:20:07 2014 gottin_o
** Last update Sat May 24 22:11:34 2014 gottin_o
*/

#include <stdlib.h>
#include "../sh.h"

void	finish(t_globalinfos *info)
{
  my_free_tab(info->env);
  free(info->prompt);
  free(info);
}
