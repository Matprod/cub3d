/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:10:10 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/20 18:22:22 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parsing(char *map_name, t_parse **parse)
{
	if (is_valid_map_name(map_name) == FALSE)
		return (free(*parse), ERROR);
	// Mettre dans init map
	(*parse)->pos_player = (t_vector){0, 0};
	(*parse)->dir_player = 0;
	(*parse)->map_name = ft_strdup(map_name);
	if (!(*parse)->map_name)
		return (error_msg(ERROR_MALLOC), free(*parse), ERROR); //LF
	//
	if (init_map(*parse) == ERROR)
		return (ERROR);
	if (check_map(*parse) == ERROR)	
		return (free_map(*parse), ERROR);
	if (is_map_surrounded((*parse)->map) == ERROR)
		return (free_map(*parse), ERROR);
	return (SUCCESS);
}

bool	is_valid_map_name(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (i < 5)
		return (error_msg(ERROR_MAP_NAME), FALSE);
	if (map[i - 4] != '.' || map[i - 3] != 'c'
		|| map[i - 2] != 'u' || map[i - 1] != 'b') //ft_strcmp?
		return (error_msg(ERROR_MAP_FORMAT), FALSE);
	return (TRUE);
}

bool	init_map(t_parse *map)
{
	if (get_map(map) == ERROR)							//OK
		return (ERROR);
	if (get_color_element(map, CEILING, 'C') == ERROR)	//OK
		return (ERROR);
	if (get_color_element(map, FLOOR, 'F') == ERROR)	//OK
		return (ERROR);
	if (get_texture_path(map) == ERROR)					//OK
		return (ERROR);
	map->map_height = map_height(map->map);
	map->map_width = map_width(map->map);
	return (SUCCESS);
}

bool	check_map(t_parse *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (is_valid_input(map->map[i][j]) == FALSE)
				return (ERROR);
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				if (map->pos_player.x != 0 || map->pos_player.y != 0)
					return (false); // ??
				map->pos_player = (t_vector){j, i};
				map->dir_player = map->map[i][j];
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
