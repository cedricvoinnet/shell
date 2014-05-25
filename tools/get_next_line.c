/*
** get_next_line.c for getnextline in /home/giudic_a/rendu
** 
** Made by giudic_a
** Login   <giudic_a@epitech.net>
** 
** Started on  Mon May 19 17:23:00 2014 giudic_a
** Last update Wed May 21 15:17:51 2014 gottin_o
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char			*re_alloc(char *str, int i)
{
  char			*tmp;

  if ((tmp = malloc(i + 2 + BUFFER_SIZE)) == NULL)
    return (NULL);
  *tmp = 0;
  strcat(tmp, str);
  free(str);
  return (tmp);
}

char			*get_next_line(const int fd)
{
  static char		buffer[BUFFER_SIZE];
  int			i;
  int			c;
  char			*str;

  i = 0;
  if ((str = malloc(BUFFER_SIZE + 2)) == NULL)
    return (NULL);
  if ((c = read(fd, buffer, BUFFER_SIZE)) <= 0)
    return (NULL);
  while (c != 0)
    {
      if (buffer[0] == '\n' || buffer[0] == '\0')
	{
	  str[i] = '\0';
	  return (str);
	}
      str[i] = buffer[0];
      str[i + 1] = '\0';
      str = re_alloc(str, i);
      if ((c = read(fd, buffer, BUFFER_SIZE)) <= 0)
	return (NULL);
      i = i + 1;
    }
  return (str);
}
