/*
** put_space_end.c for put_space_end.c in /home/gottin_o/Projets/42sh/tools
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Wed Apr 30 17:40:57 2014 gottin_o
** Last update Mon May 19 15:15:03 2014 gottin_o
*/

#include <stdlib.h>
#include <string.h>
#include "../sh.h"

char	*put_space_end(char *str)
{
  if (str[strlen(str) - 1] == ' ')
    return (str);
  else
    {
      str = realloc(str, sizeof(char) * (strlen(str) + 2));
      if (str == NULL)
	return (NULL);
      strcat(str, " ");
      return (str);
    }
}
