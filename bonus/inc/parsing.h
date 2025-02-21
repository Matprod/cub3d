/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:05:45 by allan             #+#    #+#             */
/*   Updated: 2025/02/21 11:16:46 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parsing.h
#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

# define ERROR_NO_PLAYER "Error\nNo player in the Map: Lack N, S, E or W\n"
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
# define ERROR_NO_PLAYER "Error\nNo player in the Map: Lack N, S, E or W\n"

// Structs related to PARSING
typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_parse
{
	char		**map;
	char		*map_name;
	char		*text_no;
	char		*text_so;
	char		*text_we;
	char		*text_ea;
	int		 	color_floor[3];
	int		 	color_ceiling[3];
	int		 	map_height;
	int		 	map_width;
	char		dir_player;
	t_vector	pos_player;
}				t_parse;

// PARSER
//parsing
bool			parser(char *map_name, t_parse **parser);
bool			is_valid_map_name(char *map);
bool			init_map(char *map_name, t_parse **parser);
bool			check_map(t_parse *parser);

//get_map
bool			get_map_name(char *map_name, t_parse **parser);
bool			get_map(t_parse *map);
int				get_nb_line_fd(char *map_name);
bool			skip_data_map(char *line);
bool			add_line(char **map, char *line, int *nb);
				//add close_and_free

//check_map
bool			is_valid_input(char c);
bool			is_valid_starting_position(t_parse *parser, int i, int j);
bool			is_map_surrounded(char **map);
bool			check_first_walls(char **map);
bool			check_last_walls(char **map);
bool			check_player_exist(char **map);
bool			check_empty_case(t_parse *parser, char **map);

//get_next_line
char			*get_next_line(int fd, bool error);
char			*read_and_stock(int fd, char *stack);
char			*after_endline(char *stack);
char			*before_endline(char *stack);
char			*ft_strjoin_gnl(char *s1, char const *s2);

//get_color_element
bool			get_color_element(t_parse *map, int element, char name);
bool			split_line(t_parse *map, char *line, int element, char name);
bool			check_valid_split(char **first_split, char **second_split,
				int element);
void			copy_color(int color_element[3], t_parse *map, int element);
void			error_color(int element);

//get_texture_path
bool			set_default_texture(t_parse *map);
bool			is_texture(char *line);
bool			check_split_texture(char **split, char *line);
bool			split_line_texture(t_parse *map, char *line);
bool			get_texture_path(t_parse *map);

//map_utils
int				map_height(char **map);
int				map_width(char **map);
#endif // PARSING_H
