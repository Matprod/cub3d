/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:18:29 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/14 18:11:06 by Matprod          ###   ########.fr       */
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
				/* if (map->pos_player.x != 0 || map->pos_player.y != 0)
					return (false); */
				//map->pos_player = (t_vector){j, i};
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
		while(map[i][j])
		{
			while (map[i][j] == ' ')
				j++;
			if (map[i][j] == '1')
			{

			}
		}	
		i++;
	}
	return (SUCCESS);
}
