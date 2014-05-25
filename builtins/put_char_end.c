/*
** my_catchar.c for my_catchar.c in /home/gottin_o/Projets/49sh/builtins
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Thu May 15 11:23:10 2014 gottin_o
** Last update Thu May 22 19:43:40 2014 gottin_o
*/

#include <string.h>
#include <stdlib.h>

char	*put_char_end(char *str, char character)
{
  char	*tmp;
  int	i;

  i = 0;
  tmp = malloc(sizeof(char) * strlen(str) + 2);
  if (tmp == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      ++i;
    }
  tmp[i] = character;
  ++i;
  tmp[i] = '\0';
  return (tmp);
}
