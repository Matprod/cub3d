/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:28:45 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/19 18:14:21 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_minimap_tile(t_game *game, int x_start, int y_start, int color)
{
	int	x;
	int	y;

	x = x_start;
	while (x < x_start + MINIMAP_TILE_SIZE)
	{
		y = y_start;
		while (y < y_start + MINIMAP_TILE_SIZE)
		{
			if (y == y_start || x == x_start)
				img_pix_put(&game->fps_img, x, y, COLOR_BLACK);
			else
				img_pix_put(&game->fps_img, x, y, color);
			y++;
		}
		x++;
	}
}

static void	draw_minimap_row(t_game *game,
		int start_x, int map_y, int i)
{
	int	map_x;
	int	j;
	int	color;
	int	x_start;
	int	y_start;

	j = 0;
	map_x = start_x;
	while (j < 10 && map_x < game->parsing->map_width + 20)
	{
		color = get_tile_color(game->parsing, map_x, map_y, game);
		x_start = START_MINIMAP_X + j * MINIMAP_TILE_SIZE;
		y_start = START_MINIMAP_Y + i * MINIMAP_TILE_SIZE;
		draw_minimap_tile(game, x_start, y_start, color);
		j++;
		map_x++;
	}
}

void	draw_minimap_map(t_game *game, t_parse *map)
{
	int	start_x;
	int	start_y;
	int	map_y;
	int	i;

	i = 0;
	start_x = (int)(game->player.pos.x / 64) - 5;
	start_y = (int)(game->player.pos.y / 64) - 5;
	map_y = start_y;
	while (i < 10 && map_y < map->map_height + 20)
	{
		draw_minimap_row(game, start_x, map_y, i);
		i++;
		map_y++;
	}
}
