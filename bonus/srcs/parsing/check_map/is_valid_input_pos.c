/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:59:25 by allan             #+#    #+#             */
/*   Updated: 2025/02/20 16:10:20 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_input(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == ' ')
		return (TRUE);
	return (error_msg(ERROR_MAP_CONTENT), FALSE);
}

bool	is_valid_starting_position(t_parse *parser, int i, int j)
{
	if (parser->map[i][j] == 'N' || parser->map[i][j] == 'S'
				|| parser->map[i][j] == 'E' || parser->map[i][j] == 'W')
	{
		if (parser->pos_player.x != 0 || parser->pos_player.y != 0)
			return (error_msg(ERROR_STARTING_POSITION), FALSE);
		parser->pos_player = (t_vector){j, i};
		parser->dir_player = parser->map[i][j];
	}
	return (TRUE);
}
