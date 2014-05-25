/*
** signal.c for signal.c in /home/gottin_o/Projets/42sh
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Sat May 24 15:37:52 2014 gottin_o
** Last update Sun May 25 13:45:55 2014 gottin_o
*/

#include <signal.h>
#include "../sh.h"

void	sig_handler(int sig)
{
  if ((sig = SIGINT))
    my_putstr("\nuser@42sh > ");
}

void	my_signal(void)
{
  signal(SIGINT, sig_handler);
}
