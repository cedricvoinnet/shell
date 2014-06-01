/*
** redirection_tools.c for redirection_tools.c in /home/gottin_o/Projets/42sh/parser
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Fri May 23 14:48:01 2014 gottin_o
** Last update Thu May 29 19:59:49 2014 gottin_o
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_tree.h"

int	write_open_file(char *filename, int way)
{
  int	fd;

  if (way == TRUNC)
    fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 00644);
  if (way == APPEND)
    fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 00644);
  if (fd == -1)
    {
      printf("42sh: %s: No such file or directory\n", filename);
      return (-1);
    }
  return (fd);
}

int     read_open_file(char *filename)
{
  int   fd;

  fd = open(filename, O_RDONLY);
  if (fd == -1)
    {
      printf("42sh: %s: No such file or directory\n", filename);
      return (-1);
    }
  return (fd);
}
