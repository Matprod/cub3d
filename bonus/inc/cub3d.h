/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:52 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/18 21:43:57 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <time.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "parsing.h"


# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define FOV_RADIANS 1.31
# define FOV 

# define RES_X 1280
# define RES_Y 720

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define BLUE_PIXEL 0x0000FF
# define BLACK_PIXEL 0x000000
# define WHITE_PIXEL 0xFFFFFF
# define PALE_BLUE 0x25F7C6
# define PALE_BLUE_SHADED 0x0D5243
# define COLOR_BLACK 0x000000
# define COLOR_WHITE 0xFFFFFF
# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE  0x0000FF
# define COLOR_YELLOW 0xFFFF00
# define COLOR_CYAN 0x00FFFF
# define COLOR_MAGENTA 0xFF00FF
# define COLOR_GRAY  0x808080
# define COLOR_DARK_GRAY 0x505050
# define COLOR_LIGHT_GRAY 0xD3D3D3

// DEFINE MINIMAP
# define START_MINIMAP_X 30
# define START_MINIMAP_Y 30
# define MINIMAP_SIZE 140
# define MINIMAP_TILE_SIZE 20


# define MAX_DISTANCE 10

# define CEILING 2
# define FLOOR 3

# define BUFFER_SIZE 42
# define ERROR 1
# define SUCCESS 0
# define FALSE 0
# define TRUE 1
# define RES 64
# define NOT_FOUND 0
# define NORTH_WALL "./images/DOORTRIM_1A.xpm"
# define SOUTH_WALL "./images/BRICK_3D.xpm"
# define WEST_WALL "./images/BRICK_2A.xpm"
# define EAST_WALL "./images/DOOR_2A.xpm"
# define RICK_PATH "./images/rick/"
# define MORTY_FRAMES 7
# define MORTY_START_PATH "./images/morty/frame_00"
# define FORMAT_XPM ".xpm"

# define MAX_IMAGES 14


# define ESC 65307
# define A 97
# define W 119
# define D 100
# define S 115
# define RIGHT 65361
# define LEFT 65363

# define ERROR_NBR_ARG "Error\nTwo Arguments Required: ./cub3d and map.cub\n"
# define ERROR_MAP_NAME "Error\nMap should have '.cub' format and 1 letter\n"
# define ERROR_OPEN "Error\nOpening File Failed\n"
# define ERROR_MALLOC "Error\nMalloc Initialisation Failed\n"
# define ERROR_FLOOR_COLOR "Error\nFloor Input: Invalid color\n"
# define ERROR_FLOOR_IDENTIFIER "Error\nFloor Identifier must start with 'F'\n"
# define ERROR_CEILING_COLOR "Error\nCeiling Input: Invalid color\n"
# define ERROR_TEXTURE_PATH "Error\nTexture Path: Invalid Input\n"
# define ERROR_MAP_CONTENT "Error\nMap Content: Invalid Character\n"
# define ERROR_MAP_WALL "Error\nMap is not surrounded by walls\n"
# define ERROR_STARTING_POSITION "Error\nInvalid Player Starting Position\n"

//singleton_struct
typedef enum	e_ptr_types
{
	SINGLE_PTR,
	DOUBLE_PTR
}				t_ptr_types;

typedef struct	s_node
{
	void				*data;
	t_ptr_types				type;
	struct s_node		*next;
}				t_node;

typedef struct	s_singleton
{
	t_node	*head;
}				t_singleton;
//

typedef struct s_fps 
{
	int		frames;
	double	last_time;
	double	fps;
}				t_fps;

typedef struct s_collision
{
	t_vector			point;
	char				orientation;
	float				distance;
	float				x_pos_tex;
}						t_collision;

typedef struct s_player
{
	t_vector			pos;
	t_vector			collision_pos;
	t_vector			direction;
	t_vector			speed;
	float				direction_adjust;
	t_vector			current_tile;
}						t_player;

typedef struct s_img
{
	void				*mlx_img;
	char				*addr;
	int					bpp;
	int					line_len;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct s_texture
{
	t_img				wall;
	int					text_height;
	int					text_width;
	int					floor_color;
	int					sky_color;
	t_img				north;
	t_img				north_two;
	t_img				north_three;
	t_img				south;
	t_img				east;
	t_img				west;
	t_img				morty[7];
}						t_texture;

typedef struct s_raycast_data
{
	struct s_vector		v_ray_dir;
	struct s_vector		v_step;
	struct s_vector		v_ray_length_1d;
	struct s_vector		v_map_check;
	struct s_vector		v_ray_unit_step;
	struct s_vector		collision_point;
	t_collision			collision;
	float				distance;
	char				last_step;
}						t_raycast_data;

typedef struct s_fov
{
	int					x0;
	int					y0;
	int					err;
	int					e2;
	t_vector			end;

}						t_fov;


typedef struct s_game
{
	void				*mlx;
	void				*fps_win;
	char				**map;
	int					key_states[256];
	int					key_release_states[256];
	t_fov				fov;
	t_vector			fov_left;
	t_vector			fov_right;
	t_img				fps_img;
	t_img				images[MAX_IMAGES];
	int					img_count;
	t_player			player;
	t_texture			texture;
	t_parse				*parsing;
}				t_game;


//						FUNCTIONS						//
//game
int				init_mlx(t_game **game, t_parse *parse);
int				handle_keypress(int keycode, t_game *game);
int				handle_keyrelease(int keycode, t_game *game);
void			var_init(t_game *game);
void			init_player(t_game *game);
void			move(t_game *game, char direction);
int				game_loop(void *g);
long 			time_since_start(void);
void			print_vector(t_vector vec);
long			get_time(void);
void			custom_usleep(long usec);
void			load_morty_img(t_game *game);


//render
void			render(t_game *game);
void			render_fps(t_game *game);
void			load_grid(t_game *game);
int				get_color(t_img *img, int x, int y);
unsigned int	img_pix_read(t_img *img, int x, int y);
void			load_grid(t_game *game);
void			clean_map(t_game *game);
void			clear_img(t_img *img);
t_img			create_img(t_game *game, char *path);
void			draw_minimap_map(t_game *game, t_parse *map);
bool			is_green_case(char c);
int				get_tile_color(t_parse *map, int map_x, int map_y, t_game *game);
t_img			*get_wall_texture(t_game *game, t_collision collision);
int				is_walkable(t_game *game, float x, float y);
//fov
int				is_within_minimap(int x, int y);
void 			set_err_v1(int e2, int err, t_vector end, int x0, int y0);
void			set_fov(t_game *game, int len, t_vector direction, t_vector start);
bool			set_fov2(t_game *game);
void			draw_fov_limits(t_game *game);
//raycast
void			print_circle_relative_tile_pos(t_game *game, t_vector point);
char			get_collision_orientation(char last_step, t_vector v_step);
double			get_texture_x(char last_step, t_vector v_collision_point,
					t_vector v_map_check);
t_collision		cast_two_d_ray(t_game *game, t_vector direction);

//pixel
int				pixel_out_of_bound(float x, float y, t_img *image);
t_vector		tile_to_pixel(t_vector tile_coord);
t_vector		pixel_to_tile(t_vector vector);

//shapes
void			img_pix_put(t_img *img, int x, int y, int color);
void			draw_vertical_line_2(t_img *img, t_vector pos, int len, int color);
void			draw_line_dda(t_img *img, t_vector vec1, t_vector vec2, int color);
void			draw_filled_circle(t_img *img, t_vector mid, int radius, int color);

//vector
double			vec_angle(t_vector v1, t_vector v2);
double			vec_distance(t_vector vec1, t_vector vec2);
t_vector		vec_mult(t_vector vec1, t_vector vec2);
t_vector		vec_normalize(t_vector vec);
void			vec_print(t_vector *vector, char *name);
void			vec_rotate_edit(t_vector *vector, float angle);
void			vec_rotate_rad(t_vector *vector, float angle);
t_vector		vec_rotate(t_vector vector, float angle);
t_vector		vec_scalar_mult(t_vector vec1, double i);
t_vector		vec_sum(t_vector vec1, t_vector vec2);
void			vec_to_angle(double angle, t_vector *vector);
//free
int				close_window(t_game *game);
void			close_and_free(char **array, int fd);
void			free_map(t_parse *map);
void			free_all(t_game *game);
void			free_parse(t_parse *parse);
void			free_array(char **array);

//print
void			print_array(char **array);
int				print_error(char *error);
void			print_int_array(int *array, int size);
void			error_msg(const char *error);

//singleton
t_singleton 	*get_singleton_list();
bool			add_singleton_data(void *data, t_ptr_types data_type);
bool			free_singleton_list();
void			free_singleton_data(t_node *current);

#endif