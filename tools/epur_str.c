/*
** epur_str.c for epur_str in /home/giudic_a/rendu/49sh/builtins
** 
** Made by Aurélien Giudici
** Login   <giudic_a@epitech.net>
** 
** Started on  Fri May 16 16:58:07 2014 Aurélien Giudici
** Last update Wed May 21 15:58:09 2014 gottin_o
*/

#include <stdlib.h>
#include <string.h>

char	*epur_str(char *string)
{
  int	i;
  int	j;
  char	*str;

  i = 0;
  j = 0;
  str = malloc((strlen(string) + 1) * sizeof(char));
  if (str == NULL)
    return (NULL);
  while (string[j] != '\0')
    {
      while (string[j] == ' ' || string[j] == '\t')
	j += 1;
      while (string[j] != ' ' && string[j] != '\t' && string[j])
	{
	  str[i++] = string[j++];
	  str[i] = 0;
	}
      if (string[j - 1] != ' ' && string[j - 1] != '\t')
	str[i++] = ' ';
      if (string[j] == '\0' && (str[i - 1] == ' ' || str[i - 1] == '\t'))
	str[i - 1] = '\0';
    }
  return (str);
}
