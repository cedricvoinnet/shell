/*
** copy_command_line.c for copy_command_line.c in /home/gottin_o/Projets/lexer
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Fri May 16 23:15:31 2014 gottin_o
** Last update Sat May 24 17:57:22 2014 gottin_o
*/

#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "../sh.h"

int	check_if_sepa(char *str, int position)
{
  int	i;

  i = 0;
  while (sepa_tab[i].sepa)
    {
      if (my_strncmp_beg(str, sepa_tab[i].sepa,
                         sepa_tab[i].size + 1, position) == 0)
        return (1);
      ++i;
    }
  return (0);
}

int	instruction_size(char *str, int i)
{
  int	size;

  size = 0;
  while (str[i] && str[i] != SPACE &&
         check_if_sepa(str, i) == 0)
    {
      ++size;
      ++i;
    }
  return (size);
}

int	add_separator(t_instructions **list, char *str, int i)
{
  char	*separator;
  int	p;

  p = 0;
  while (my_strncmp_beg(str, sepa_tab[p].sepa,
			sepa_tab[p].size + 1, i) != 0)
    ++p;
  separator = strdup(sepa_tab[p].sepa);
  put_in_list(list, separator);
  i = i + sepa_tab[p].size;
  if (str[i] == SPACE)
    i = i + 1;
  return (i);
}

int	fill_instruction(t_instructions **list, char *str, int i, int size)
{
  int	j;
  char	*instruction;

  j = 0;
  if (size != 0)
    {
      instruction = malloc(sizeof(char) * (size + 1));
      if (instruction == NULL)
	return (-1);
      while (j != size)
	{
	  instruction[j] = str[i];
	  ++j;
	  ++i;
	}
      instruction[j] = '\0';
      put_in_list(list, instruction);
    }
  if (str[i] == SPACE)
    i = i + 1;
  if (check_if_sepa(str, i) == 1)
    i = add_separator(list, str, i);
  return (i);
}

t_instructions		*copy_in_list(char *str)
{
  int			i;
  int			size;
  t_instructions	*list;

  i = 0;
  if (str == NULL)
    return (NULL);
  list = NULL;
  while (str[i] != '\0')
    {
      size = instruction_size(str, i);
      i = fill_instruction(&list, str, i, size);
      if (i == -1)
	return (NULL);
    }
  return (list);
}
