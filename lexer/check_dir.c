/*
** check_dir.c for 42sh in /home/verove_j/rendu/42sh/lexer
** 
** Made by verove_j
** Login   <verove_j@epitech.net>
** 
** Started on  Fri May 23 12:08:51 2014 verove_j
** Last update Fri May 23 21:07:14 2014 gottin_o
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int		check_dir(char *file_name)
{
  struct stat	buffer;
  int		i;

  i = stat(file_name, &buffer);
  if (i == -1)
    return (-1);
  if (i != -1)
    {
      if (buffer.st_mode & S_IFDIR)
	return (1);
    }
  return (-1);
}
