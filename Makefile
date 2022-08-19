NAME = pipex
CC = gcc
CFLAG = -Wall -Wextra -Werror 

SRC =	pipex.c check_file.c

DEP = pipex.h

LIBFT = 		libft/libft.a
LIBFT_PATH = 	libft/

all: $(NAME) 


$(NAME): $(SRC) $(DEP) $(LIBFT)
	$(CC) $(CFLAG) -o $(NAME) $(SRC) $(LIBFT)

$(LIBFT) :
	@make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT_PATH)

fclean: 
	rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all
	
.PHONY: clean fclean re all

