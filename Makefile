
SRC		= 	main.c \
			ft_ls.c \
			flags.c \
			
OBJ		= $(SRC:.c=.o)

NAME 	= ft_ls

CFLAGS = -Wall -Wextra -Werror

CC = @gcc

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft/
	@gcc $(OBJ) $(FLAG) libft/libft.a -o $(NAME)
	@echo "\033[92mDone for ft_ls\033[0m"
	
clean :
	@make clean -C ./libft/
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C ./libft/
	@rm -rf $(NAME)

norme:
	@norminette $(SRC)

re : fclean all
