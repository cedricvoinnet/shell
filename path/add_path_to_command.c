/*
** add_path_to_command.c for add_path_to_command.c in /home/gottin_o/Projets/49sh
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Sun May 11 16:22:22 2014 gottin_o
** Last update Sun May 11 17:50:01 2014 gottin_o
*/

#include <stdlib.h>
#include <string.h>
#include "../sh.h"

char    **add_path_to_command(char *command, char **env)
{
  char  **command_with_path;
  int	new_size;
  int	i;

  i = 0;
  if (command && env)
    {
      command_with_path = extract_path_tab(env);
      if (command_with_path == NULL)
	return (NULL);
      while (command_with_path[i] != NULL)
	{
	  new_size = strlen(command_with_path[i]) + strlen(command) + 2;
	  command_with_path[i] = realloc(command_with_path[i], 
					 sizeof(char) * new_size);
	  if (command_with_path[i] == NULL)
	    return (NULL);
	  strcat(command_with_path[i], "/");
	  strcat(command_with_path[i], command);
	  ++i;
	}
      return (command_with_path);
    }
  return (NULL);
}
