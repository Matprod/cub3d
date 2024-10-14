/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:10:10 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/14 15:59:02 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_map(t_map *data_map)
{
	data_map->map = get_map(data_map->map_name);
	if (!data_map->map)
		return (printf("Error : with stocking the map\n"), ERROR);
	get_color_ceiling(&data_map);
	get_color_floor(&data_map);
	get_texture_path(data_map);
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
void	init_map(t_map *data_map)
{
	if (!data_map->text_no)
		data_map->text_no = ft_strdup(NORTH_WALL);
	if (!data_map->text_so)
		data_map->text_so = ft_strdup(SOUTH_WALL);
	if (!data_map->text_ea)
		data_map->text_ea = ft_strdup(EAST_WALL);
	if (!data_map->text_we)
		data_map->text_we = ft_strdup(WEST_WALL);
}


bool	parsing(char *map_name, t_map **data_map)
{
	if (!is_valid_map_name(map_name))
	{
		free(*data_map);
		return (ERROR);
	}
	(*data_map)->map_name = ft_strdup(map_name);
	if (parse_map(*data_map) == ERROR)
		return (ERROR);
	if (check_input_map((*data_map)->map) == ERROR)
	{
		free_all(*data_map);
		return (ERROR);
	}
	return (SUCCESS);
}
