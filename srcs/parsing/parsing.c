/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:10:10 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/17 11:26:26 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_map(t_parse *map)
{
	map->map = get_map(map->map_name);
	if (!map->map)
		return (printf("Error : with stocking the map\n"), ERROR);
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
	{
		printf("Error : map should have '.cub' format and at least 1 letter\n");
		return (FALSE);
	}
	if (map[i - 1] != 'b' || map[i - 2] != 'u' || map[i - 3] != 'c'
		|| map[i - 4] != '.')
	{
		printf("Error : map should have '.cub' format and at least 1 letter\n");
		return (FALSE);
	}
	return (TRUE);
}

bool	parsing(char *map_name, t_parse **parse)
{
	if (!is_valid_map_name(map_name))
	{
		free(*parse);
		return (ERROR);
	}
	(*parse)->pos_player = (t_vector){0, 0};
	(*parse)->dir_player = 0;
	(*parse)->map_name = ft_strdup(map_name);
	if (parse_map(*parse) == ERROR)
		return (ERROR);
	if (check_input_map(*parse) == ERROR)
	{
		free_map(*parse);
		return (ERROR);
	}
	if (is_map_surrounded((*parse)->map) == ERROR)
	{
		free_map(*parse);
		return (ERROR);
	}
	return (SUCCESS);
}
