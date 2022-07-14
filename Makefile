NAME = pipex
CC = gcc
CFLAG = -Wall -Wextra -Werror 

SRC =	pipex.c check_file.c

OBJ = $(patsubst %.c, %.o, $(SRC))

LIBFT = 		libft/libft.a
LIBFT_PATH = 	libft/
LIBFTSRC =		libft/ft_printf.c libft/ft_strnstr.c \
				libft/ft_split.c libft/ft_strjoin.c	\
				libft/ft_put*.c libft/ft_strlen.c \
				libft/ft_strncmp.c libft/ft_substr.c \
				libft/ft_strlcat.c

all: $(NAME) 


$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(LIBFTSRC)

$(LIBFT) :
	@make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT_PATH)

fclean: clean	
	rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all
	
.PHONY: clean fclean re all

