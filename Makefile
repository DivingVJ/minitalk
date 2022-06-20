# What is the function of this? 
NAME = pipex.a
CC = gcc
CFLAG = -Wall -Wextra -Werror

SRC =	pipex.c

OBJ = $(patsubst %.c, %.o, $(SRC))

LIBFT = libft/libft.a
LIBFT_PATH = libft/
LIBFTOBJ = libft/ft_put*.o libft/ft_strlen.o

all: $(NAME) 


$(NAME): $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ) $(LIBFTOBJ)

$(OBJ): $(SRC) $(DEP)
	$(CC) $(CFLAG) -c $(SRC)

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

