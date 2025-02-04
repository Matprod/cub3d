/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:58:35 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/02 15:50:35 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_circle_relative_tile_pos(t_game *game, t_vector point)
{
	point = vec_scalar_mult(point, 64);
	point = vec_sum(point, game->player.pos);
}

char	get_collision_orientation(char last_step, t_vector v_step)
{
	if (last_step == 'x')
	{
		if (v_step.x == 1)
			return ('W');
		else
			return ('E');
	}
	else
	{
		if (v_step.y == 1)
			return ('N');
		else
			return ('S');
	}
}

double	get_texture_x(char last_step, t_vector v_collision_point,
		t_vector v_map_check)
{
	if (last_step == 'x')
		return (v_collision_point.y - v_map_check.y * 64);
	else
		return (v_collision_point.x - v_map_check.x * 64);
}
