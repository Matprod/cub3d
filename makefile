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
MLX_FLAGS			= lib/mlx/libmlx.a lib/mlx/libmlx_Linux.a -L. -lXext -L. -lX11
RM					= rm -f


# Concatenate all source files
SRCS 				=	srcs/

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
					make all

$(LIBFT):
					make -C ./libft

$(MLX):
					make -C ./libmlx.a

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					$(CC) $(CFLAGS) $(INC) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					mkdir -p $(@D)
					$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft
					@make clean -C ./libmlx.a
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(MLX)

re: fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re
