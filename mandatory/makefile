# Standard
NAME				= cub3d

# Directories
LIBFT_DIR			= lib/libft/libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/
MLX_A 				= libmlx.a
MLX_DIR 			= lib/mlx/
# Compiler and CFlags
CC					= cc
CFLAGS 				= -Wall -Wextra -Werror -I

#-Werror
MLX_FLAGS			= -L. -lXext -L. -lX11
MLX_FLAGS_OBJS 		= lib/mlx/libmlx.a lib/mlx/libmlx_Linux.a -L. -lXext -L. -lX11
RM					= rm -f


# Concatenate all source files
SRCS 				=	srcs/main.c\
						srcs/free.c\
						srcs/utils.c\
						srcs/singleton.c\
						srcs/print.c\
						srcs/events.c\
						srcs/game_loop.c\
						srcs/init_windows.c\
						srcs/parsing/parser.c\
						srcs/parsing/init_map/init_map.c\
						srcs/parsing/init_map/get_map_name.c\
						srcs/parsing/init_map/get_map.c\
						srcs/parsing/init_map/get_next_line.c\
						srcs/parsing/init_map/get_color_element.c\
						srcs/parsing/init_map/get_texture_path.c\
						srcs/parsing/init_map/get_height_width.c\
						srcs/parsing/check_map/check_map.c\
						srcs/parsing/check_map/is_valid_input_pos.c\
						srcs/parsing/check_map/is_map_surrounded.c\
						srcs/vector/vec_angle.c\
						srcs/vector/vec_distance.c\
						srcs/vector/vec_mult.c\
						srcs/vector/vec_normalize.c\
						srcs/vector/vec_print.c\
						srcs/vector/vec_rotate.c\
						srcs/vector/vec_rotate_edit.c\
						srcs/vector/vec_rotate_rad.c\
						srcs/vector/vec_scalar_mult.c\
						srcs/vector/vec_sum.c\
						srcs/vector/vec_to_angle.c\
						srcs/shapes/circle.c\
						srcs/shapes/line.c\
						srcs/shapes/pixel.c\
						srcs/render/raycast_utils.c\
						srcs/render/raycast.c\
						srcs/render/render_fps.c\
						srcs/render/render.c\

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
all:	$(NAME)

$(LIBFT_DIR):
	make -C ./lib/libft
	make -C ./lib/mlx


$(NAME): 			$(OBJ) $(LIBFT_DIR) $(MLX)
					$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT_DIR) $(MLX_FLAGS_OBJS) -lm -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					mkdir -p $(@D)
					$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(MAKE) clean -C lib/libft
	$(RM) $(OBJ)
	

fclean: clean
	$(MAKE) fclean -C lib/libft
	$(RM) ${NAME}

re: fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re
