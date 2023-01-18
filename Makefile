NAME = minishell
SRCS =	srcs/main.c \
		srcs/init.c \
		srcs/reinit.c \
		srcs/exec/exec_cmd.c \
		srcs/exec/built_in.c \
		srcs/exec/built_in_unset.c \
		srcs/exec/signal.c \
		srcs/exec/set_env.c \
		srcs/exec/echo.c \
		srcs/exec/delimiteur.c \
		srcs/exec/prompt.c \
		srcs/exec/built_in_env.c \
		srcs/exec/shell_exec.c \
		srcs/exec/redirect.c \
		srcs/exec/redirect2.c \
		srcs/exec/utils.c \
		srcs/exec/pipe.c \
		srcs/exec/sort_env.c \
		srcs/parsing/env.c \
		srcs/parsing/parsing.c \
		srcs/parsing/ft_split_ms.c \
		srcs/parsing/free_tab.c	\
		srcs/parsing/parsing_cmd.c \
		srcs/parsing/l_dchev.c \
		srcs/parsing/l_dchev_word.c \
		srcs/parsing/other_chev.c \
		srcs/parsing/stock_o_chev.c \
		srcs/parsing/check_syntax.c \
		srcs/parsing/get_args.c \
		srcs/parsing/o_chev_quote.c \
		srcs/parsing/status_error.c \
		srcs/parsing/ft_substrr.c \
		srcs/parsing/o_chev_quote2.c \

HEADER = minishell.h
OBJS = ${SRCS:.c=.o}

all: $(NAME)

libft/libft.a:
	make -C ./libft

$(NAME): $(SRCS) libft/libft.a
	gcc -Wall -Wextra -Werror $(SRCS) libft/libft.a -I include -lreadline -L /Users/fatilly/homebrew/Cellar/readline/8.1.2/lib -I /Users/fatilly/homebrew/Cellar/readline/8.1.2/include -o minishell

clean:
	$(MAKE) -C ./libft clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all
