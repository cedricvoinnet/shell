/*
** my_tree.h for my_tree.h in /home/gottin_o/Projets/tree
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Mon May 12 19:48:32 2014 gottin_o
** Last update Thu May 29 22:38:18 2014 gottin_o
*/

#ifndef		MY_TREE_H_
# define	MY_TREE_H_

# define	SEMICOLON ";"
# define	PIPE "|"
# define	R_R ">"
# define	R_DR ">>"
# define	L_R "<"
# define	L_DR "<<"
# define	OR "||"
# define	AND "&&"
# define	END 0
# define	SPACE ' '
# define	TAB '\t'
# define	NO_SEP 0
# define	SUCESS 0
# define	FAILURE -1
# define	TRUNC	1
# define	APPEND	2

#include	"../sh.h"

typedef struct  s_builtin
{
  char          *builtin;
  int           size;
  t_globalinfos	*(*fptr)();
}               t_builtin;

typedef struct  s_separators
{
  char          *sepa;
  int           size;
  int		priority;
}               t_sepa;

typedef struct	s_node
{
  struct s_node	*left;
  struct s_node	*right;
  char		*command;
  int		separator_id;
}		t_node;

extern t_sepa	sepa_tab[];

int		find_separator(char *s1, char *s2, int pos, int size);
int		rightmost_sepa_position(char *str, int sepa_index, int *separator);
int		create_if_not_exists(char *filename);
int		split_next(char *str, int *priority, int i);
int		split_position(char *str);
int		print_typo_error(char *name);
int		write_open_file(char *filename, int way);
int		read_open_file(char *filename);
int		get_sepa_infos(char *str, int position, int *separator_size, int *separator_id);

char		*get_left_part(char *str, int split_pos);
char		*get_right_part(char *str, int split_pos, int sepa_index);
char		**line_splitter(char *str, int where_to_split, int separator_size);
char		**add_path_to_command(char *command, char **env);

void		init_func(t_globalinfos *(*tab[])(t_node *node, int *fd, t_globalinfos *info));
void		my_free_tab(char **tab);
void		free_tree(t_node *node);

t_globalinfos   *exec_launch(char **, t_globalinfos *);
t_globalinfos	*l_db_redir(t_node *, int *, t_globalinfos *);
t_globalinfos	*r_db_redir(t_node *, int *, t_globalinfos *);
t_globalinfos	*r_redir(t_node *, int *, t_globalinfos *);
t_globalinfos	*l_redir(t_node *, int *, t_globalinfos *);
t_globalinfos	*semicolon(t_node *, int *, t_globalinfos *);
t_globalinfos	*func_or(t_node *, int *, t_globalinfos *);
t_globalinfos	*func_and(t_node *, int *, t_globalinfos *);
t_globalinfos	*func_pipe(t_node *, int *, t_globalinfos *);
t_globalinfos   *exec(t_node *node, int *fd, t_globalinfos *info);
t_globalinfos	*env_reader(t_globalinfos *info, char **tab);
t_globalinfos	*my_setenv(t_globalinfos *info, char **command_wt);
t_globalinfos	*cd(t_globalinfos *info, char **command_wt);
t_globalinfos	*my_unsetenv(t_globalinfos *info, char **command_wt);
t_globalinfos	*my_exit(t_globalinfos *info, char **command_wt);
t_globalinfos	*my_echo(t_globalinfos *info, char **command_wt);

#endif /* MY_TREE_H_ */
