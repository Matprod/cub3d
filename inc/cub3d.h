/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:52 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/16 11:46:48 by Matprod          ###   ########.fr       */
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

# define MAX_DISTANCE 10

# define BUFFER_SIZE 42
# define ERROR 1
# define SUCCESS 0
# define FALSE 0
# define TRUE 1
# define RES 64
# define NORTH_WALL "./images/pixel_art_1.xpm"
# define SOUTH_WALL "./images/pixel_art_2.xpm"
# define WEST_WALL "./images/pixel_art_3.xpm"
# define EAST_WALL "./images/pixel_art.xpm"

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
bool		parsing(char *map_name, t_parse **data_map);
char		**get_map(char *map_name);
char		*get_next_line(int fd);
bool		get_color_ceiling(t_parse *map);
bool		get_color_floor(t_parse *map);
bool		get_texture_path(t_parse *map);
bool		check_input_map(t_parse *map);
int			map_height(char **map);
int			map_width(char **map);
bool		is_map_surrounded(char **map);
//game
int			handle_keypress(int keycode, t_game *game);
int			handle_keyrelease(int keycode, t_game *game);
void		var_init(t_game *game);
void		init_player(t_game *game);
//vector
double		vec_angle(t_vector v1, t_vector v2);
double		vec_distance(t_vector vec1, t_vector vec2);
t_vector	vec_mult(t_vector vec1, t_vector vec2);
t_vector	vec_normalize(t_vector vec);
void		vec_print(t_vector *vector, char *name);
void		vec_rotate_edit(t_vector *vector, float angle);
void		vec_rotate_rad(t_vector *vector, float angle);
t_vector	vec_rotate(t_vector vector, float angle);
t_vector	vec_scalar_mult(t_vector vec1, double i);
t_vector	vec_sum(t_vector vec1, t_vector vec2);
void		vec_to_angle(double angle, t_vector *vector);
//free
int			close_window(t_game *game);
void		close_and_free(char **array, int fd);
void		free_map(t_parse *map);
void		free_all(t_game *game);
void		free_parse(t_parse *parse);
void		free_array(char **array);

//print
void	print_array(char **array);
int		print_error(char *error);
void	print_int_array(int *array, int size);

#endif