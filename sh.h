/*
** 42sh.h for sh.h in /home/gottin_o/Projets/42sh
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Tue Apr 29 15:10:53 2014 gottin_o
** Last update Sun Jun  1 13:56:54 2014 voinne_c
*/

#ifndef		SH_H_
# define	SH_H_

# define	DEFAULT_USER "user"
# define	PROMPT_END "42sh > \0"
# define	EXIT_FAIL -1

typedef struct	s_globalinfos
{
  char		**env;
  char		*prompt;
  int		exit_now;
  int		exit_value;
  int		exec_status;
}               t_globalinfos;

t_globalinfos	*init(char **env);
t_globalinfos	*my_tree(char *command, t_globalinfos *info);
t_globalinfos	*get_old(t_globalinfos *info);
t_globalinfos	*get_pwd(t_globalinfos *info);

void		my_putchar(char a);
void		my_putstr(char *str);
void		finish(t_globalinfos *info);
void		my_free_tab(char **tab);
void		my_signal(void);

int		locate_var(char **env, char *var_name);
int		lexer(char *str, t_globalinfos *info);
int		table_sizer(char **tab);
int		my_getnbr(char *str);
int		check_dir(char *file_name);

char		**my_str_to_wordtab(char *str);
char		**extract_env(char **env);
char		**extract_path_tab(char **env);
char		**add_path_to_command(char *command, char **env);

char		*line_reader();
char		*choose_prompt();
char		*strcut(char *str, int size);
char		*my_realloc(char *str, int bytes);
char		*put_space_end(char *str);
char		*get_prompt(char **env);
char		*get_next_line(const int fd);
char		*put_char_end(char *str, char character);
char		*pass_folder(char *str);

extern char	*g_prompt;

#endif		/* SH_H_ */
