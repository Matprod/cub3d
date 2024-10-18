/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:10:10 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/18 16:33:07 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_map(t_parse *map)
{
	map->map = get_map(map->map_name);
	if (!map->map)
		return (ERROR);
	get_color_ceiling(map);
	get_color_floor(map);
	get_texture_path(map);
	map->map_height = map_height(map->map);
	map->map_width = map_width(map->map);
	return (SUCCESS);
}

bool	is_valid_map_name(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (i < 5)
		return (error_msg(ERROR_MAP_NAME), FALSE);
	if (map[i - 4] != '.' || map[i - 3] != 'c'
		|| map[i - 2] != 'u' || map[i - 1] != 'b') //ft_strcmp
		return (error_msg(ERROR_MAP_FORMAT), FALSE);
	return (TRUE);
}

bool	parsing(char *map_name, t_parse **parse)
{
	if (is_valid_map_name(map_name) == ERROR)			//OK
		return (free(*parse), ERROR);
	// Mettre dans init map
	(*parse)->pos_player = (t_vector){0, 0};
	(*parse)->dir_player = 0;
	(*parse)->map_name = ft_strdup(map_name);
	if (!(*parse)->map_name)
		return (error_msg(ERROR_MALLOC), free(*parse), ERROR);
	//
	if (init_map(*parse) == ERROR)				//OK
		return (ERROR);
	if (parse_map(*parse) == ERROR)				//OK
		return (free_map(*parse), ERROR);
	if (is_map_surrounded((*parse)->map) == ERROR)	//OK
		return (free_map(*parse), ERROR);
	return (SUCCESS);
}
