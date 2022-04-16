SRC		=	main.c map.c parse_arg.c
SRC_GNL	=	get_next_line.c get_next_line_utils.c
SRC_DIR	=	source
OBJ_DIR	= 	obj
GNL_DIR	=	get_next_line
OBJ_GNL_DIR = gnl_obj
OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_GNL	=	$(addprefix $(OBJ_GNL_DIR)/, $(SRC_GNL:.c=.o))

NAME	=	so_long

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g3

all		:	$(NAME)

$(NAME)	:	mk_dir libft $(OBJ_GNL) $(OBJ)
			$(CC) $(OBJ) $(OBJ_GNL) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 \
			-lm -lz -Llibft -lft -o $(NAME)

$(OBJ_DIR)/%.o		:	$(SRC_DIR)/%.c
			$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(OBJ_GNL_DIR)/%.o	:	$(GNL_DIR)/%.c
			$(CC) $(CFLAGS) -c $< -o $@

libft	:
			make -C libft bonus

mk_dir :
			mkdir -p $(OBJ_DIR)
			mkdir -p $(OBJ_GNL_DIR)

clean	:
			make -C libft clean
			rm -rf $(OBJ_DIR)
			rm -rf $(OBJ_GNL_DIR)

fclean	:	clean
			rm -f $(NAME)
			make -C libft fclean

re		:	fclean all

.PHONY	:	all clean fclean re libft mk_dir