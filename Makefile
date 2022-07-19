NAME = pipex
CC = gcc
CFLAG = -Wall -Wextra -Werror 

SRC =	pipex.c check_file.c

BONUS_SRC = pipex_bonus.c check_file_bonus.c

DEP = pipex.h

DEP_BONUS = pipex_bonus.h

LIBFT = 		libft/libft.a
LIBFT_PATH = 	libft/

all: $(NAME) 


$(NAME): $(SRC) $(DEP) $(LIBFT)
	$(CC) $(CFLAG) -o $(NAME) $(SRC) $(LIBFT)

bonus: $(BONUS_SRC) $(DEP_BONUS) $(LIBFT)
	$(CC) $(CFLAG) -o $(NAME) $(BONUS_SRC) $(LIBFT)	

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

