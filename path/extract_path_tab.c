/*
** extract_path_tab.c for extract_path_tab.c in /home/gottin_o/Projets/49sh/tools
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Sun May 11 16:46:37 2014 gottin_o
** Last update Fri May 30 17:07:03 2014 gottin_o
*/

#include <stdlib.h>
#include <stdio.h>
#include "../sh.h"

int	path_tab_size(char *path_line)
{
  int	i;
  int	cpt;

  i = 5;
  cpt = 1;
  if (path_line[i] == '\0')
    return (-1);
  while (path_line[i] != '\0')
    {
      if (path_line[i] == ':')
        ++cpt;
      ++i;
    }
  return (cpt);
}

char	*line_malloc(char *env, int pos)
{
  int	size;
  char	*tab;

  size = 0;
  while (env[pos] != ':' && env[pos] != '\0')
    {
      ++size;
      ++pos;
    }
  tab = malloc(sizeof(char) * (size + 1));
  if (tab == NULL)
    return (NULL);
  return (tab);
}

int	fill_line(char *env, char *tab, int pos)
{
  int	i;

  i = 0;
  while (env[pos] && env[pos] != ':')
    {
      tab[i] = env[pos];
      ++i;
      pos = pos + 1;
    }
  tab[i] = '\0';
  return (pos);
}

char	**extract_path_tab_next(char **path_tab, char *path_line)
{
  int	i;
  int	j;

  i = 5;
  j = 0;
  while (path_line[i] != '\0')
    {
      path_tab[j] = line_malloc(path_line, i);
      if (path_tab[j] == NULL)
	return (NULL);
      i = fill_line(path_line, path_tab[j], i);
      if (path_line[i] != '\0')
        ++i;
      ++j;
    }
  path_tab[j] = NULL;
  return (path_tab);
}

char	**extract_path_tab(char **env)
{
  char	**path_tab;
  int	size;
  int	path;

  path = locate_var(env, "PATH=");
  if (path == -1)
    {
      printf("Warning, [PATH] not found.\n");
      return (NULL);
    }
  size = path_tab_size(env[path]);
  path_tab = malloc(sizeof(char *) * (size + 1));
  if (path_tab == NULL)
    return (NULL);
  path_tab = extract_path_tab_next(path_tab, env[path]);
  return (path_tab);
}
