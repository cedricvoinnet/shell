/*
** my_getnbr.c for my_getnbr.c in /home/gottin_o/Projets/42sh/tools
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Sat May 24 14:47:41 2014 gottin_o
** Last update Sat May 24 14:48:44 2014 gottin_o
*/

int	my_getnbr(char *str)
{
  int	nb;
  int	n;
  int	i;

  i = 0;
  nb = 0;
  n = 1;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	n = n * -1;
      i = i + 1;
    }
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10;
      nb = nb + str[i] - 48;
      i = i + 1;
    }
  return (nb * n);
}
