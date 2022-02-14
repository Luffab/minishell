NAME = minishell
SRCS =	srcs/exec/main.c \
		srcs/exec/exec_cmd.c \
		srcs/exec/built_in.c \
		srcs/exec/readline.c \
		srcs/exec/signal.c \

HEADER = minishell.h
OBJS = ${SRCS:.c=.o}

all: $(NAME)

libft/libft.a:
	make -C ./libft

$(NAME): $(SRCS) libft/libft.a
	gcc -Wall -Wextra -Werror $(SRCS) libft/libft.a -I include -lreadline -o minishell

clean:
	$(MAKE) -C ./libft clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all