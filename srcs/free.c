/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:35:57 by Matprod           #+#    #+#             */
/*   Updated: 2025/01/02 16:40:29 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	free_texture(t_parse *map)
{
	if (map->text_ea)
		free(map->text_ea);
	if (map->text_no)
		free(map->text_no);
	if (map->text_we)
		free(map->text_we);
	if (map->text_so)
		free(map->text_so);
}

void	free_map(t_parse *map)
{
	if (map->map)
		free_array(map->map);
	if (map->map_name)
		free(map->map_name);
	free_texture(map);
	free(map);
}

void	free_parse(t_parse *parse)
{
	free_map(parse);
	free(parse);
}

void free_images(t_game *game)
{
	int i;
	
	i = 0;
	while (i < game->img_count)
	{
		if (game->images[i].mlx_img)
			mlx_destroy_image(game->mlx, game->images[i].mlx_img);
		i++;
	}
	game->img_count = 0;
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->fps_win);
	mlx_destroy_image(game->mlx, game->fps_img.mlx_img);
	free_images(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_singleton_list();
	exit(0);
}


