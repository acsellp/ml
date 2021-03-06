NAME = lem

SRCS = srcs/main.c srcs/tree.c srcs/visu.c

INCL = -I ./includes -I./libft

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): 
		#make -C libft re
		gcc $(SRCS) $(FLAGS) $(INCL) -L./libft -lft -o $(NAME)

clean:
		#make -C libft clean

libft:
		make -C libft re

fclean: clean
		rm -rf $(NAME)

re: fclean all

