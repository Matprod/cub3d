/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:05:45 by allan             #+#    #+#             */
/*   Updated: 2024/10/24 14:42:48 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parsing.h
#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

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
	int		 color_floor[3];
	int		 color_ceiling[3];
	int		 map_height;
	int		 map_width;
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
bool			init_texture(t_parse *data_map);
bool			is_texture(char *line);
bool			check_split_texture(char **split, char *line);
bool			split_line_texture(t_parse *map, char *line);
bool			get_texture_path(t_parse *map);

//map_utils
int				map_height(char **map);
int				map_width(char **map);
#endif // PARSING_H
