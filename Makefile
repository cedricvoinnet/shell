##
## Makefile for Makefile in /home/gottin_o/Projets/42sh
## 
## Made by gottin_o
## Login   <gottin_o@epitech.net>
## 
## Started on  Fri Apr 25 12:08:20 2014 gottin_o
## Last update Fri May 30 18:07:32 2014 gottin_o
##

NAME =		42sh

SRC =		42sh.c \
		builtins/extract_env.c \
		builtins/env_reader.c \
		builtins/my_exit.c \
		builtins/cd.c \
		builtins/my_setenv.c \
		builtins/my_unsetenv.c \
		builtins/put_char_end.c \
		builtins/pwd.c \
		builtins/my_echo.c \
		init/init.c \
		init/init_check_tab.c \
		init/separators_tab_init.c \
		init/get_prompt.c \
		init/signal.c \
		lexer/check_syntax.c \
		lexer/check_type.c \
		lexer/check_type_next.c \
		lexer/check_dir.c \
		lexer/readlist.c \
		lexer/copy_in_list.c \
		lexer/lexer.c \
		lexer/put_in_list.c \
		parser/line_splitter.c \
		parser/parser.c \
		parser/redir_func.c \
		parser/sepa_func.c \
		parser/execution.c \
		parser/redirection_tools.c \
		parser/init_func.c \
		parser/split_position.c \
		path/extract_path_tab.c \
		path/add_path_to_command.c \
		path/locate_var.c \
		tools/str_works.c \
		tools/my_str_to_wordtab.c \
		tools/printing.c \
		tools/my_free_tab.c \
		tools/put_space_end.c \
		tools/epur_str.c \
		tools/free_list.c \
		tools/my_getnbr.c \
		tools/get_next_line.c \
		tools/free_tree.c \
		tools/display_errors.c \
		tools/finish.c

OBJ =		$(SRC:.c=.o)

CC = 		gcc

CFLAGS =	-Wall -Wextra

RM = 		rm -f

all: 		$(NAME)

$(NAME): 	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean: 
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
