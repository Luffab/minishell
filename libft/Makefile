NAME = libft.a
SRCS = ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strlen.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_strcmp.c\
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strnstr.c \
		  ft_atoi.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		get_next_line.c \
		  get_next_line_utils.c
BONUS =		ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
		  	ft_lstsize_bonus.c \
		  	ft_lstlast_bonus.c \
		  	ft_lstadd_back_bonus.c \
		  	ft_lstdelone_bonus.c \
		  	ft_lstclear_bonus.c \
		  	ft_lstiter_bonus.c \
		  	ft_lstmap_bonus.c
HEADER = libft.h
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = $(BONUS:.c=.o)

.c.o: $(HEADER)
	gcc -Wall -Wextra -Werror -I includes -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f  $(NAME)

re: fclean all