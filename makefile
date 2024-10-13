# Standard
NAME				= cub3d

# Directories
LIBFT				= lib/libft/libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/
MLX_A 				= libmlx.a
MLX_DIR 			= lib/mlx/
# Compiler and CFlags
CC					= cc
CFLAGS				= -Wall -Wextra -Werror -I
MLX_FLAGS			= -L. -lXext -L. -lX11
RM					= rm -f


# Concatenate all source files
SRCS 				=	srcs/main.c\
						srcs/parsing.c\
						srcs/map_parsing.c\
						srcs/get_texture_path.c\
						srcs/get_color_floor.c\
						srcs/get_color_ceiling.c\
						srcs/get_next_line.c\
						srcs/free.c\
						srcs/print.c\

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
					make all

$(LIBFT):
					make -C ./lib/libft

$(MLX):
					make -C ./mlx

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT) $(MLX)
					$(CC) $(CFLAGS) $(INC) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					mkdir -p $(@D)
					$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./lib/libft
					@make clean -C ./lib/mlx
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(MLX)

re: fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re
