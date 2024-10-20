/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:18:29 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/20 19:59:12 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_map(t_parse *parser)
{
	int	i;
	int	j;

	i = 0;
	while (parser->map[i])
	{
		j = 0;
		while(parser->map[i][j])
		{
			if (is_valid_input(parser->map[i][j]) == FALSE)
				return (ERROR);
			if (is_valid_starting_position(parser, i, j) == FALSE)
				return (ERROR);
			j++;
		}
		i++;
	}
	if (is_map_surrounded(parser->map) == FALSE)
		return (ERROR);
	return (SUCCESS);
}
