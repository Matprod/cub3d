/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:27:46 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/14 19:10:05 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	create_img(t_game *game, char *path)
{
	t_img		img;

	img.mlx_img = mlx_xpm_file_to_image(game->mlx, path,
			&img.width, &img.height);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp,
			&img.line_len, &img.endian);
	return (img);
}

void	load_img(t_game *game)
{
	game->texture.north = create_img(game, game->parsing->text_no);
	game->texture.south = create_img(game, game->parsing->text_so);
	game->texture.west = create_img(game, game->parsing->text_we);
	game->texture.east = create_img(game, game->parsing->text_ea);
}

void	init_player(t_game *game)
{
	game->player.pos.x = (int)game->parsing->pos_player.x * 64 + 32;
	game->player.pos.y = (int)game->parsing->pos_player.y * 64 + 32;
	game->player.speed.x = 0;
	game->player.speed.y = 0;
	game->player.collision_pos.x = game->player.pos.x + 32;
	game->player.collision_pos.y = game->player.pos.y + 32;
	game->player.direction.x = 0;
	game->player.direction.y = 0;
	if (game->parsing->dir_player == 'N')
		game->player.direction.y = -1;
	else if (game->parsing->dir_player == 'S')
		game->player.direction.y = 1;
	else if (game->parsing->dir_player == 'W')
		game->player.direction.x = -1;
	else if (game->parsing->dir_player == 'E')
		game->player.direction.x = 1;
	game->player.direction_adjust = 10;
}

int	rgb_to_argb(int tab[3])
{
	return ((0xFF << 24) | (tab[0] << 16) | (tab[1] << 8) | tab[2]);
}

void	var_init(t_game *game)
{
	int	i;

	i = 256;
	while (i--)
	{
		game->key_states[i] = 0;
		game->key_release_states[i] = 1;
	}
	init_player(game);
	game->map = game->parsing->map;
	game->texture.sky_color = rgb_to_argb(game->parsing->color_ceiling);
	game->texture.floor_color = rgb_to_argb(game->parsing->color_floor);
	load_img(game);
	mlx_put_image_to_window(game->mlx, game->fps_win,
		game->fps_img.mlx_img, 0, 0);
}