/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:18:29 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/20 16:09:33 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
# define ERROR_NO_PLAYER "Error\nNo player in the Map: Lack N, S, E or W\n"

bool	check_map(t_parse *parser)
{
	int	i;
	int	j;

	i = 0;
	while (parser->map[i])
	{
		j = 0;
		while (parser->map[i][j])
		{
			if (is_valid_input(parser->map[i][j]) == FALSE)
				return (ERROR);
			if (is_valid_starting_position(parser, i, j) == FALSE)
				return (ERROR);
			j++;
		}
		i++;
	}
	if (check_empty_case(parser, parser->map) == FALSE)
		return (error_msg("Error: Empty Space(s) found in the map\n"), ERROR);
	if (is_map_surrounded(parser->map) == FALSE)
		return (ERROR);
	if (check_player_exist(parser->map) == FALSE)
		return (ERROR);
	return (SUCCESS);
}

bool	check_empty_case(t_parse *parser, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (i == 0 || i == parser->map_height - 1 || j == 0
					|| !map[i][j + 1] || map[i][j + 1] == '\n')
					return (FALSE);
				if ((int)ft_strlen(map[i + 1]) - 1 < j
					|| (int)ft_strlen(map[i - 1]) - 1 < j)
					return (FALSE);
				if (map[i + 1][j] == ' ' || map[i - 1][j] == ' '
					|| map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
					return (FALSE);
			}
		}
	}
	return (TRUE);
}

bool	check_player_exist(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				return (TRUE);
			}
		}
	}
	return (error_msg("Error\nNo player in the Map: Lack N, S, E or W\n"),
		FALSE);
}
