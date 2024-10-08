/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:10:10 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/03 18:11:42 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_map(t_map *data_map)
{
	data_map->map = get_map(data_map->map_name);
	if (!data_map->map)
		return (printf("Error : with stocking the map\n"), ERROR);
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

bool	parsing(char *map_name, t_map **data_map)
{
	if (!is_valid_map_name(map_name))
		return (ERROR);
	*data_map = malloc(sizeof(t_map));
	if (!data_map)
		return (printf("Error malloc data_map\n"), ERROR);
	(*data_map)->map_name = ft_strdup(map_name);
	if (parse_map(*data_map) == ERROR)
		return (ERROR);
	return (SUCCESS);
}