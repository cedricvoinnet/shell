/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/voinne_c/B1_Igraph
** 
** Made by voinne_c
** Login   <voinne_c@epitech.net>
** 
** Started on  Wed Dec  4 11:20:48 2013 voinne_c
** Last update Wed May 21 17:43:14 2014 gottin_o
*/

#include <stdlib.h>
#include "../sh.h"

static int	count_str(char *str)
{
  int		i;
  int		c;

  i = 0;
  c = 0;
  while (str[i] != 0)
    {
      if ((str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != 0))
	  || str[i + 1] == 0)
	{
	  c++;
	  i++;
	}
      else
	i++;
    }
  return (c);
}

static char	*my_memcpy(char *dest, char *src, int n)
{
  int		i;

  i = 0;
  while (i != n)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = 0;
  return (dest);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  char	**tab;
  int	n;
  char	*p;

  p = str;
  n = 0;
  if ((tab = malloc(sizeof(char*) * (count_str(str) + 1))) == NULL)
    return (NULL);
  while (n != count_str(str))
    {
      i = 0;
      while (p[i] != ' ' && p[i] != 0)
	i++;
      if (i != 0)
	{
	  if ((tab[n] = malloc(sizeof(char) * (i + 1))) == NULL)
	    return (NULL);
	  my_memcpy(tab[n++], p, i);
	}
      p = p + i + 1;
    }
  tab[n] = NULL;
  return (tab);
}
