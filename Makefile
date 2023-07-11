SRCS	=	main.c \
			./sources/utils/lib.c \
			./sources/utils/remove_all_quote.c \
			./sources/utils/remove_all.c \
			./sources/utils/remove_dollar.c \
			./sources/utils/remove_dollar2.c \
			./sources/utils/utils_remove_dollar.c \
			./sources/utils/utils_remove_dollar1.c \
			./sources/utils/remove_from_command.c \
			./sources/utils/treat_dollar.c \
			./sources/utils/add_space_between_redir.c \
			./sources/utils/remove_space_env.c \
			./sources/utils/utils.c \
			./sources/utils/utils01.c \
			./sources/utils/utils02.c \
			./sources/utils/utils03.c \
			./sources/utils/utils04.c \
			./sources/utils/ft_copy.c \
			./sources/utils/utils_cpy.c \
			./sources/utils/ft_split.c \
			./sources/errors/put_error.c \
			./sources/errors/errors.c \
			./sources/errors/check_parse_error.c \
			./sources/errors/check_redirection_error.c \
			./sources/errors/utils_check_redir.c \
			./sources/lexer/init_lexer.c \
			./sources/lexer/init.c \
			./sources/free/free_lexer.c \
			./sources/free/free_env.c \
			./sources/free/free_other.c \
			./sources/redirection/redirection.c \
			./sources/redirection/make_redirection.c \
			./sources/redirection/here_doc.c \
			./sources/exec/exec.c \
			./sources/exec/exec2.c \
			./sources/exec/processexec.c \
			./sources/exec/processexec2.c \
			./sources/exec/processexec3.c \
			./sources/exec/treat_fork.c \
			./sources/built_in/build_in.c \
			./sources/built_in/cd.c \
			./sources/built_in/utils_echo.c \
			./sources/built_in/echo.c \
			./sources/built_in/env.c \
			./sources/built_in/check_export.c \
			./sources/built_in/export.c \
			./sources/built_in/pwd.c \
			./sources/built_in/unset.c \
			./sources/built_in/shlvl.c \
			./sources/built_in/utils_built_in1.c \
			./sources/built_in/utils_built_in2.c \
			./sources/built_in/exit.c

OBJS	=	${SRCS:.c=.o}

CC		=	cc -Wall -Werror -Wextra
RM		=	rm -f
NAME	=	minishell

all:		${NAME}

.c.o:
			$(CC) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) -lreadline 

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re