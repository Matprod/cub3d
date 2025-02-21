/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:47:01 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/21 13:22:30 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	custom_usleep(unsigned int time)
{
	volatile unsigned int	counter;

	counter = 0;
	while (counter < time)
		counter++;
	counter = 0;
	while (counter < time)
		counter++;
	counter = 0;
	while (counter < time)
		counter++;
	counter = 0;
	while (counter < time)
		counter++;
}

void	render(t_game *game)
{
	render_fps(game);
	custom_usleep(1000000);
	mlx_put_image_to_window(game->mlx, game->fps_win, game->fps_img.mlx_img, 0,
		0);
}
