/*
** my_strncmp_beg.c for my_strncmp_beg.c in /home/gottin_o/Projets/lexer
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Fri May 16 23:17:30 2014 gottin_o
** Last update Fri May 30 17:46:07 2014 gottin_o
*/

int	my_strncmp_beg(char *s1, char *s2, int nb, int beg)
{
  int   i;

  i = 0;
  while ((i + 1) != nb)
    {
      if (s2[i] == s1[beg])
        {
          ++i;
          ++beg;
        }
      else
        return (1);
    }
  return (0);
}
