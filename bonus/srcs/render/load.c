/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:44:40 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/04 16:23:10 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	load_grid(t_game *game)
{
	int			i;
	int			j;
	t_vector	pos;

	i = -1;
	while (++i < map_height(game->map))
	{
		j = -1;
		while (++j < map_width(game->map))
		{
			pos.x = j * 64;
			pos.y = i * 64;
		}
	}
} */

void	clean_map(t_game *game)
{
	int			i;
	int			j;

	i = -1;
	while (++i < map_height(game->map))
	{
		j = -1;
		while (++j < map_width(game->map))
		{
			if (game->map[i][j] == 'B')
				game->map[i][j] = '0';
		}
	}
}

void	clear_img(t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < RES_X)
	{
		j = -1;
		while (++j < RES_Y)
		{
			img_pix_put(img, i, j, BLACK_PIXEL);
		}
	}
}
