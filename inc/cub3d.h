/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:52 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/13 22:19:17 by Matprod          ###   ########.fr       */
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

typedef struct map
{
	char	**map;
	char	*map_name;
	char	*text_no;
	char	*text_so;
	char	*text_we;
	char	*text_ea;
	int		color_floor[3];
	int		color_ceiling[3];
	int		map_height;
	int		map_width;
}	t_map;

//						FUNCTIONS						//
//parsing
bool	parsing(char *map_name, t_map **data_map);
char	**get_map(char *map_name);
char	*get_next_line(int fd);
bool	get_color_ceiling(t_map **map);
bool	get_color_floor(t_map **map);
bool	get_texture_path(t_map *map);
bool	check_input_map(char **map);

//free
void	close_and_free(char **array, int fd);
void	free_map(t_map *map);
void	free_all(t_map *map);
void	free_array(char **array);
//print
void	print_array(char **array);
int		print_error(char *error);
void	print_int_array(int *array, int size);

#endif