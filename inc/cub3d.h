/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:52 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/18 11:22:04 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"


# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define FOV_RADIANS 1.5707963268
# define FOV 60

# define RES_X 1280
# define RES_Y 720

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define BLUE_PIXEL 0x0000FF
# define BLACK_PIXEL 0x000000
# define WHITE_PIXEL 0xFFFFFF
# define PALE_BLUE 0x25F7C6
# define PALE_BLUE_SHADED 0x0D5243

# define MAX_DISTANCE 10

# define BUFFER_SIZE 42
# define ERROR 1
# define SUCCESS 0
# define FALSE 0
# define TRUE 1
# define RES 64
# define NORTH_WALL "./images/BRICK_1A.xpm"
# define SOUTH_WALL "./images/BRICK_3D.xpm"
# define WEST_WALL "./images/BRICK_2A.xpm"
# define EAST_WALL "./images/DOOR_2A.xpm"

# define ESC 65307
# define A 97
# define W 119
# define D 100
# define S 115
# define RIGHT 65361
# define LEFT 65363

typedef struct s_vector
{
	double				x;
	double				y;
}						t_vector;

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
	t_img				south;
	t_img				east;
	t_img				west;
}						t_texture;

typedef struct s_parse
{
	char		**map;
	char		*map_name;
	char		*text_no;
	char		*text_so;
	char		*text_we;
	char		*text_ea;
	int			color_floor[3];
	int			color_ceiling[3];
	int			map_height;
	int			map_width;
	char		dir_player;
	t_vector	pos_player;
}						t_parse;

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

typedef struct s_game
{
	void				*mlx;
	void				*fps_win;
	char				**map;
	int					key_states[256];
	int					key_release_states[256];
	t_img				fps_img;
	t_player			player;
	t_texture			texture;
	t_parse				*parsing;
}				t_game;


//						FUNCTIONS						//
//parsing
bool			parsing(char *map_name, t_parse **data_map);
char			**get_map(char *map_name);
char			*get_next_line(int fd);
bool			get_color_ceiling(t_parse *map);
bool			get_color_floor(t_parse *map);
bool			get_texture_path(t_parse *map);
bool			check_input_map(t_parse *map);
int				map_height(char **map);
int				map_width(char **map);
bool			is_map_surrounded(char **map);
void			init_texture(t_parse *data_map);
//game
int				handle_keypress(int keycode, t_game *game);
int				handle_keyrelease(int keycode, t_game *game);
void			var_init(t_game *game);
void			init_player(t_game *game);
void			move(t_game *game, char direction);
int				game_loop(void *g);
//render
void			render(t_game *game);
void			render_fps(t_game *game);
void			load_grid(t_game *game);
int				get_color(t_img *img, int x, int y);
unsigned int	img_pix_read(t_img *img, int x, int y);
void			load_grid(t_game *game);
void			clean_map(t_game *game);
void			clear_img(t_img *img);
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

#endif