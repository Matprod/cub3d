/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:47:01 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/21 13:26:28 by Matprod          ###   ########.fr       */
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

int	get_tile_color(t_parse *map, int map_x, int map_y, t_game *game)
{
	if (map == NULL || map->map == NULL)
		return (COLOR_BLACK);
	if (map_y < 0 || map_y >= map->map_height || map_x < 0
		|| map_x >= map->map_width)
		return (COLOR_BLACK);
	if (map->map[map_y] == NULL)
		return (COLOR_BLACK);
	if (map_x >= (int)ft_strlen(map->map[map_y]))
		return (COLOR_BLACK);
	if (map_x == (int)(game->player.pos.x / 64)
		&& map_y == (int)(game->player.pos.y / 64))
		return (COLOR_RED);
	if (is_green_case(map->map[map_y][map_x]))
		return (COLOR_GREEN);
	if (map->map[map_y][map_x] == '1')
		return (COLOR_GRAY);
	return (COLOR_BLACK);
}

void	render(t_game *game)
{
	render_fps(game);
	mlx_put_image_to_window(game->mlx, game->fps_win, game->fps_img.mlx_img, 0,
		0);
	draw_minimap_map(game, game->parsing);
}
