/*
** redirection_tools.c for redirection_tools.c in /home/gottin_o/Projets/42sh/parser
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Fri May 23 14:48:01 2014 gottin_o
** Last update Sun May 25 14:45:36 2014 gottin_o
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_tree.h"

int	create_if_not_exists(char *filename)
{
  int	fd;

  fd = open(filename, O_CREAT, 00644);
  if (fd == -1)
    {
      my_putstr("Error while creating the file.\n");
      return (-1);
    }
  close(fd);
  return (0);
}

int	write_open_file(char *filename, int way)
{
  int	fd;

  if (way == TRUNC)
    fd = open(filename, O_WRONLY | O_TRUNC);
  if (way == APPEND)
    fd = open(filename, O_WRONLY | O_APPEND);
  if (fd == -1)
    {
      my_putstr("Error while opening the file.\n");
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
      my_putstr("Error while opening the file\n");
      return (-1);
    }
  return (fd);
}
