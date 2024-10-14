/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:18:29 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/13 22:46:32 by Matprod          ###   ########.fr       */
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

bool	check_input_map(char **map)
{
	int	i;
	int	j;
	int len;

	i = 0;
	while (map[i])
	{
		j = 0;
		len = ft_strlen(map[i]);
		while(map[i][j])
		{
			if (is_valid_input(map[i][j]) == FALSE && j != len - 1)
			{
				return (ERROR);
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
