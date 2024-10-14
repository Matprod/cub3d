/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:52 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/14 18:33:24 by Matprod          ###   ########.fr       */
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

# define BUFFER_SIZE 42
# define ERROR 1
# define SUCCESS 0
# define FALSE 0
# define TRUE 1
# define RES 64
# define NORTH_WALL "north_wall.xpm"
# define SOUTH_WALL "south_wall.xpm"
# define WEST_WALL "west_wall.xpm"
# define EAST_WALL "east_wall.xpm"

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
bool	parsing(char *map_name, t_parse **data_map);
char	**get_map(char *map_name);
char	*get_next_line(int fd);
bool	get_color_ceiling(t_parse *map);
bool	get_color_floor(t_parse *map);
bool	get_texture_path(t_parse *map);
bool	check_input_map(t_parse *map);
int		map_height(char **map);
int		map_width(char **map);

//free
void	close_and_free(char **array, int fd);
void	free_map(t_parse *map);
void	free_all(t_parse *map);
void	free_array(char **array);
//print
void	print_array(char **array);
int		print_error(char *error);
void	print_int_array(int *array, int size);

#endif