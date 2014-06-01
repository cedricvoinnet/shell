/*
** get_prompt.c for get_prompt.c in /home/gottin_o/Projets/42sh/init
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Mon May 19 18:26:53 2014 gottin_o
** Last update Fri May 30 15:35:28 2014 gottin_o
*/

#include <stdlib.h>
#include <string.h>
#include "../sh.h"

char	*get_user(char **env)
{
  char	*user;
  int	i;

  if ((i = locate_var(env, "USER=")) == -1)
    return (DEFAULT_USER);
  else
    {
      user = strdup(env[i]);
      while (*user != '=')
	++user;
      ++user;
    }
  return (user);
}

char	*get_prompt(char **env)
{
  char	*prompt;
  char	*user;
  int	size;

  user = get_user(env);
  size = strlen(user) + strlen(PROMPT_END) + 1;
  if ((prompt = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  bzero(prompt, size);
  strcat(prompt, user);
  strcat(prompt, "@");
  strcat(prompt, PROMPT_END);
  g_prompt = strdup(prompt);
  return (prompt);
}
