/*
** lexer.h for lexer.h in /home/gottin_o/Projets/42sh
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Fri Apr 25 11:55:11 2014 gottin_o
** Last update Sun Jun  1 13:57:45 2014 voinne_c
*/

#ifndef		LEXER_H_
# define	LEXER_H_

# define	SEMICOLON ";"
# define	PIPE "|"
# define	R_REDIR ">"
# define	R_DBREDIR ">>"
# define	L_REDIR "<"
# define	L_DBREDIR "<<"
# define	OR "||"
# define	AND "&&"

# define	SPACE ' '
# define	TAB '\t'

# define	OTH 1
# define	SEP 2
# define	RED 3
# define	SMC 4
# define	END 0

#include	"../sh.h"

typedef	struct		s_separators
{
  char			*sepa;
  int			size;
  int			priority;
}			t_sepa;

typedef struct		s_syntax
{
  int			type;
  int			*followed_by;
}			t_syntax;

typedef struct		s_instructions
{
  char			*instruction;
  int			type;
  struct s_instructions	*next;
}			t_instructions;

t_instructions		*copy_in_list(char *str);

void			free_list(t_instructions **list);
void			my_free_tab(char **tab);
void			assign_types(t_instructions *list, char **env);
void			init_check_tab(int (*check_tab[])(char *, char **));

int			my_strncmp_beg(char *s1, char *s2, int nb, int beg);
int			check_type(char *str, char **env);
int			is_a_sep(char *str, char **env);
int			is_a_file(char *str, char **env);
int			is_a_exe(char *str, char **env);
int			is_a_semicolon(char *str, char **env);
int			is_a_red(char *str, char **env);
int			is_other(char *str, char **env);
int			put_in_list(t_instructions **list, char *instruction);
int			print_typo_error(char *name);
int			print_no_such_file(char *name);
int			print_unexp_token(char *name);
int			print_newline_error(void);
int			check_compatibility(int type1, int type2);
int			gere_error(int type1, char *str, char *str2);
int			check_syntax(t_instructions *list);

char			*my_strdup(char *str);
char			*epur_spaces(char *str);
char			*unrollup(t_instructions *list);
char			*epur_str(char *string);

extern t_sepa		sepa_tab[];
extern t_syntax		syntax_tab[];

#endif /* LEXER_H_ */
