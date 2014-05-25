/*
** init_func.c for init_func.c in /home/gottin_o/Projets/42sh/parser
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Thu May 22 20:15:42 2014 gottin_o
** Last update Fri May 23 19:00:28 2014 gottin_o
*/

#include "my_tree.h"

void	init_func(t_globalinfos *(*tab[])(t_node *node, int *fd, t_globalinfos *info))
{
  tab[0] = &semicolon;
  tab[1] = &func_or;
  tab[2] = &func_and;
  tab[3] = &func_pipe;
  tab[4] = &l_db_redir;
  tab[5] = &r_db_redir;
  tab[6] = &l_redir;
  tab[7] = &r_redir;
}
