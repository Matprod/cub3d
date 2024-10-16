/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:18:29 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/16 16:34:33 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_input(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W'|| c == ' ')
		return (TRUE);
	return (FALSE);
}

bool	check_input_map(t_parse *map)
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
					return (false);
				map->pos_player = (t_vector){j, i};
				map->dir_player = map->map[i][j];
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

bool	is_map_surrounded(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] == '0')
		{
			printf("error | map[i] =%s | map[i][j] =%c | j = %d\n",map[i], map[i][j], j);
			return (ERROR);
		}
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][ft_strlen(map[i])-1] == '0')
		{
			printf("error | map[i] =%s | map[i][j] =%c | j = %d\n",map[i], map[i][j], j);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}
