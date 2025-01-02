/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:27:46 by Matprod           #+#    #+#             */
/*   Updated: 2025/01/02 17:50:08 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	create_img(t_game *game, char *path)
{
	t_img	img;

	if (game->img_count >= MAX_IMAGES)
		printf("Error: maximum number of images (%d) reached\n", MAX_IMAGES);
	img.mlx_img = mlx_xpm_file_to_image(game->mlx, path,
			&img.width, &img.height);
	if (!img.mlx_img)
	{
		printf("Error: failed to load image from %s\n", path);
		return (img);
	}
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp,
			&img.line_len, &img.endian);
	game->images[game->img_count++] = img;
	return (img);
}


void	load_img(t_game *game)
{
	game->texture.north = create_img(game, game->parsing->text_no);
	if (!game->texture.north.mlx_img)
		return (printf("Error loading north texture\n"), (void)0);
	game->texture.north_two = create_img(game, "./images/DOORTRIM_1B.xpm");
	if (!game->texture.north.mlx_img)
		return (printf("Error loading north two texture\n"), (void)0);
	game->texture.north_three = create_img(game, "./images/DOORTRIM_1C.xpm");
	if (!game->texture.north.mlx_img)
		return (printf("Error loading north three texture\n"), (void)0);
	game->texture.south = create_img(game, game->parsing->text_so);
	if (!game->texture.south.mlx_img)
		return (printf("Error loading south texture\n"), (void)0);
	game->texture.west = create_img(game, game->parsing->text_we);
	if (!game->texture.west.mlx_img)
		return (printf("Error loading west texture\n"), (void)0);
	game->texture.east = create_img(game, game->parsing->text_ea);
	if (!game->texture.east.mlx_img)
		return (printf("Error loading east texture\n"), (void)0);
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
	/* game->mouse_right = false;
	game->mouse_left = false; */
	init_player(game);
	game->map = game->parsing->map;
	game->texture.sky_color = rgb_to_argb(game->parsing->color_ceiling);
	game->texture.floor_color = rgb_to_argb(game->parsing->color_floor);
	game->img_count = 0;
	load_img(game);
	mlx_put_image_to_window(game->mlx, game->fps_win,
		game->fps_img.mlx_img, 0, 0);
}