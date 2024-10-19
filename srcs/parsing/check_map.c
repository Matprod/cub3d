/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:18:29 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/19 12:36:41 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_input(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W'|| c == ' ')
		return (TRUE);
	return (error_msg(ERROR_MAP_CONTENT), FALSE);
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
			error_msg(ERROR_MAP_WALL);
			printf("At coordonate: y:%d x:%d Value: %c\n", i, j, map[i][j]);
			return (ERROR);
		}
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][ft_strlen(map[i])-1] == '0')
		{
			error_msg(ERROR_MAP_WALL);
			printf("At coordonate: y:%d x:%d Value: %c\n", i, j, map[i][j]);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}
