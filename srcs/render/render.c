/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:47:01 by Matprod           #+#    #+#             */
/*   Updated: 2024/11/22 18:38:52 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void draw_circle(t_game *game)
{
	int x, y;
	int center_x = START_MINIMAP_X + MINIMAP_SIZE / 2;
	int center_y = START_MINIMAP_Y + MINIMAP_SIZE / 2;
	int radius = 3;
	int color = 0x0000000;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			// Vérifie que le pixel est dans le cercle
			if (x * x + y * y <= radius * radius)
				img_pix_put(&game->fps_img, center_x + x, center_y + y, color);
			x++;
		}
		y++;
	}
} */

/* void draw_circle_param(t_img *img, int center_x, int center_y, int radius, int color)
{
	int x;
	int y;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			// Vérifie si le point est dans le cercle
			if (x * x + y * y <= radius * radius)
				img_pix_put(img, center_x + x, center_y + y, color);
			x++;
		}
		y++;
	}
} */

void draw_minimap_map(t_game *game, t_parse *map)
{
	int start_x, start_y;
	int map_x, map_y;
	int i, j;
	int color;

	start_x = (int)(game->player.pos.x / 64) - 5;
	start_y = (int)(game->player.pos.y / 64) - 5;

	// Parcourir les cases visibles
	map_y = start_y;
	i = 0;
	while (i < 10 && map_y < map->map_height)
	{
		map_x = start_x;
		j = 0;
		while (j < 10 && map_x < map->map_width)
		{
			if (map_x >= 0 && map_y >= 0 && map_y < map->map_height && map_x < map->map_width)
			{
				if (map_x == (int)(game->player.pos.x / 64) && map_y == (int)(game->player.pos.y / 64))
					color = 0xFF0000;
				else
				{
					if (map->map[map_y][map_x] == '1') // Mur
						color = 0x666666;
					else if (map->map[map_y][map_x] == '0')
						color = 0x00FF00; // Vert
					else
						color = 0x000000; //BLACK
				}
			}
			else
				color = 0x000000; // Hors limite (noir)
				
			int x_start = START_MINIMAP_X + j * MINIMAP_TILE_SIZE;
			int y_start = START_MINIMAP_Y + i * MINIMAP_TILE_SIZE;
			int x = x_start;
			while (x < x_start + MINIMAP_TILE_SIZE)
			{
				int y = y_start;
				while (y < y_start + MINIMAP_TILE_SIZE)
				{
					img_pix_put(&game->fps_img, x, y, color);
					y++;
				}
				x++;
			}
			j++;
			map_x++;
		}
		i++;
		map_y++;
	}
}


void	render(t_game *game)
{
	render_fps(game);
	custom_usleep(9999999);
	custom_usleep(9999999);
	mlx_put_image_to_window(game->mlx, game->fps_win, game->fps_img.mlx_img, 0,
		0);
	draw_minimap_map(game, game->parsing);
	//draw_circle(game);
}
