/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:10:10 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/13 21:56:24 by Matprod          ###   ########.fr       */
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
	//get_texture_path(data_map);
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
	data_map->text_no = ft_strdup(NORTH_WALL);
	data_map->text_so = ft_strdup(SOUTH_WALL);
	data_map->text_ea = ft_strdup(EAST_WALL);
	data_map->text_we = ft_strdup(WEST_WALL);
	/* for (int i = 0; i < 3; i++)
    {
        data_map->color_floor[i] = 0;  // Initialisation des couleurs du sol
        data_map->color_ceiling[i] = 0;  // Initialisation des couleurs du plafond
    } */
}
bool	is_valid_input(char nig)
{
	if (nig == '1' || nig == '0' || nig == 'N' || nig == 'S' || nig == 'E'
		|| nig == 'W'|| nig == ' ')
		return (TRUE);
	return (FALSE);
}

bool	check_input_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (is_valid_input(map[i][j]) == FALSE)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

/* bool	is_map_surrounded(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == ' ')
				j++;
			if (map[i][j])
		}	
		i++;
	}
	return (SUCCESS);
} */

bool	parsing(char *map_name, t_map **data_map)
{
	if (!is_valid_map_name(map_name))
		return (ERROR);
	if (!data_map)
		return (printf("Error malloc data_map\n"), ERROR);
	(*data_map)->map_name = ft_strdup(map_name);
	if (parse_map(*data_map) == ERROR)
		return (ERROR);
	init_map(*data_map);
	/* if (check_input_map((*data_map)->map) == ERROR)
		return (ERROR); */
	return (SUCCESS);
}