# What is the function of this? 
NAME = pipex
CC = gcc
CFLAG = -Wall -Wextra -Werror

SRC =	pipex.c

OBJ = $(patsubst %.c, %.o, $(SRC))

LIBFT = libft/libft.a
LIBFT_PATH = libft/
LIBFTSRC = libft/ft_strlen.c

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

