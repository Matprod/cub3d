/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_surrounded.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:58:30 by allan             #+#    #+#             */
/*   Updated: 2025/01/02 09:34:41 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_surrounded(char **map)
{
	if (check_first_walls(map) == ERROR)
		return (FALSE);
	if (check_last_walls(map) == ERROR)
		return (FALSE);
	return (TRUE);
}

bool	check_first_walls(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] == '0')
		{
			error_msg(ERROR_MAP_WALL);
			printf("Coordinate: y:%ld, x:%ld value:%c: Should be a wall\n",
				i, j, map[i][j]);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

bool	check_last_walls(char **map)
{
	size_t	i;
	size_t	last_char;

	i = 0;
	while (map[i])
	{
		last_char = ft_strlen(map[i]) - (size_t) 1;
		if (map[i][last_char] == '0')
		{
			error_msg(ERROR_MAP_WALL);
			printf("Coordinate: y:%ld, x:%ld value:%c: Should be a wall\n",
				i, last_char, map[i][last_char]);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}
