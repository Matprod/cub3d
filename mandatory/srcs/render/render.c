/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:47:01 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/19 19:01:37 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_game *game)
{
	render_fps(game);
	mlx_put_image_to_window(game->mlx, game->fps_win, game->fps_img.mlx_img, 0,
		0);
}
