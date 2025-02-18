/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:40:35 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/18 22:00:11 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_within_minimap(int x, int y)
{
	return (x >= START_MINIMAP_X && x < START_MINIMAP_X + 200
		&& y >= START_MINIMAP_Y && y < START_MINIMAP_Y + 200);
}

void	set_err_v1(t_game *game)
{
	if (game->fov.e2 > -abs((game->fov.end.y / 64.0 * MINIMAP_TILE_SIZE)
			- game->fov.y0))
	{
		game->fov.err -= abs((game->fov.end.y / 64.0 * MINIMAP_TILE_SIZE)
				- game->fov.y0);
		if (game->fov.x0 < game->fov.end.x / 64.0 * MINIMAP_TILE_SIZE)
			game->fov.x0 += 1;
		else
			game->fov.x0 += -1;
	}
}

void	set_fov(t_game *game, int len, t_vector direction, t_vector start)
{
	game->fov.end.x = start.x + direction.x * len;
	game->fov.end.y = start.y + direction.y * len;
	game->fov.x0 = (int)(start.x / 64.0 * MINIMAP_TILE_SIZE);
	game->fov.y0 = (int)(start.y / 64.0 * MINIMAP_TILE_SIZE);
	game->fov.err = abs((int)(game->fov.end.x / 64.0 * MINIMAP_TILE_SIZE)
			- game->fov.x0)
		- abs((game->fov.end.y / 64.0 * MINIMAP_TILE_SIZE) - game->fov.y0);
}

bool	set_fov2(t_game *game)
{
	if (game->fov.x0 == (game->fov.end.x / 64.0 * MINIMAP_TILE_SIZE)
		&& game->fov.y0 == (game->fov.end.y / 64.0 * MINIMAP_TILE_SIZE))
		return (false);
	game->fov. e2 = 2 * game->fov.err;
	if (game->fov.e2 > -abs((game->fov.end.y / 64.0 * MINIMAP_TILE_SIZE)
			- game->fov.y0))
	{
		game->fov.err -= abs((game->fov.end.y / 64.0 * MINIMAP_TILE_SIZE)
				- game->fov.y0);
		if (game->fov.x0 < game->fov.end.x / 64.0 * MINIMAP_TILE_SIZE)
			game->fov.x0 += 1;
		else
			game->fov.x0 += -1;
	}
	return (true);
}
