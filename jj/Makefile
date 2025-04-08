CC = cc 
FLAGS = -Wall -Werror -Wextra

LIBS = -L/usr/include/minilibx-linux -lmlx -lX11 -lXext

LIBFT = libft/libft.a

NAME = so_long

SRC =  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c check_errors.c so_long.c errors.c free.c load.c move.c utli_function.c check_map.c setup_game.c

OBJ = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(FLAGS)  -c $< -o $@

all : $(NAME)

$(LIBFT) :
	make  -C libft

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME)

clean :
	make clean -C libft 
	rm -f $(OBJ)
fclean : clean
	make fclean -C libft 
	rm -f $(NAME)

re : clean all

.PHONY: all re clean fclean
