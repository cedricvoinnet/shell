/*
** signal.c for signal.c in /home/gottin_o/Projets/42sh
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Sat May 24 15:37:52 2014 gottin_o
** Last update Fri May 30 15:40:11 2014 gottin_o
*/

#include <signal.h>
#include "../sh.h"

char	*g_prompt;
 
void		sig_handler(int sig)
{
  if ((sig = SIGINT))
    {
      my_putchar('\n');
      my_putstr(g_prompt);
    }
}

void		my_signal(void)
{
  signal(SIGINT, sig_handler);
}
