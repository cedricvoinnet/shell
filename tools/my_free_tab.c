/*
** my_free_tab.c for my_free_tab.c in /home/gottin_o/Projets/49sh/tools
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Sun May 11 18:39:34 2014 gottin_o
** Last update Sun May 11 18:40:28 2014 gottin_o
*/

#include <stdlib.h>

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      ++i;
    }
  free(tab);
}
