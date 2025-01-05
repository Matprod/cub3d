/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:47:01 by Matprod           #+#    #+#             */
/*   Updated: 2025/01/05 12:45:25 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_green_case(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
		return (TRUE);
	return (FALSE);
}

static int get_tile_color(t_parse *map, int map_x, int map_y, t_game *game)
{
	if (map == NULL || map->map == NULL)
		return (COLOR_BLACK);
	if (map_y < 0 || map_y >= map->map_height || map_x < 0 || map_x >= map->map_width)
		return (COLOR_BLACK);
	if (map->map[map_y] == NULL)
		return (COLOR_BLACK);
	if (map_x >= (int)ft_strlen(map->map[map_y]))
		return (COLOR_BLACK);
	if (map_x == (int)(game->player.pos.x / 64) && map_y == (int)(game->player.pos.y / 64))
		return (COLOR_RED);
	if (is_green_case(map->map[map_y][map_x]))
		return (COLOR_GREEN);
	if (map->map[map_y][map_x] == '1')
		return (COLOR_GRAY);
	return (COLOR_BLACK);
}

static void draw_minimap_tile(t_game *game, int x_start, int y_start, int color)
{
	int	x;
	int	y;

	x = x_start;
	while (x < x_start + MINIMAP_TILE_SIZE)
	{
		y = y_start;
		while (y < y_start + MINIMAP_TILE_SIZE)
		{
			img_pix_put(&game->fps_img, x, y, color);
			y++;
		}
		x++;
	}
}

static void draw_minimap_row(t_game *game, t_parse *map, int start_x, int map_y, int i)
{
	int	map_x;
	int	j;
	int color;
	int x_start;
	int y_start;

	j = 0;
	map_x = start_x;
	while (j < 10 && map_x < map->map_width)
	{
		color = get_tile_color(map, map_x, map_y, game);
		x_start = START_MINIMAP_X + j * MINIMAP_TILE_SIZE;
		y_start = START_MINIMAP_Y + i * MINIMAP_TILE_SIZE;
		draw_minimap_tile(game, x_start, y_start, color);
		j++;
		map_x++;
	}
}

void draw_minimap_map(t_game *game, t_parse *map)
{
	int	start_x;
	int	start_y;
	int	map_y;
	int i;

	i = 0;
	start_x = (int)(game->player.pos.x / 64) - 5;
	start_y = (int)(game->player.pos.y / 64) - 5;
	map_y = start_y;
	while (i < 10 && map_y < map->map_height)
	{
		draw_minimap_row(game, map, start_x, map_y, i);
		i++;
		map_y++;
	}
	i = 0;
	while(i < 5)
	{
		img_pix_put(&game->fps_img, (int)(game->player.pos.x / 64 + i), (int)(game->player.pos.y / 64), COLOR_RED);
		i++;
	}
}


void	render(t_game *game)
{
	render_fps(game);
	custom_usleep(15);
	mlx_put_image_to_window(game->mlx, game->fps_win, game->fps_img.mlx_img, 0,
		0);
	draw_minimap_map(game, game->parsing);

}
