/*
** printing.c for printing.c in /home/gottin_o/Projets/42sh/tools
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Tue Apr 29 19:48:21 2014 gottin_o
** Last update Mon May 19 17:46:16 2014 gottin_o
*/

#include <unistd.h>

void	my_putchar(char a)
{
  write(1, &a, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      ++i;
    }
}
