/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:41:06 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/18 21:42:39 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float get_player_angle(t_player *player)
{
	return atan2(player->direction.y, player->direction.x);
}

void update_fov_vectors(t_player *player, t_vector *fov_left, t_vector *fov_right)
{
	float fov_half = 30.0 * M_PI / 180.0;
	float angle = get_player_angle(player);

	fov_left->x = cos(angle - fov_half);
	fov_left->y = sin(angle - fov_half);
	fov_right->x = cos(angle + fov_half);
	fov_right->y = sin(angle + fov_half);
}

void draw_vector(t_game *game, t_vector start, t_vector direction, int len)
{	
	bool boolean;

	boolean = true;
	set_fov(game, len, direction, start);
    while (is_within_minimap(game->fov.x0, game->fov.y0) && boolean == true)
    {
        img_pix_put(&game->fps_img, game->fov.x0, game->fov.y0, 0x0000FF);
        boolean = set_fov2(game);
        if (game->fov.e2 < abs((game->fov.end.x / 64.0 * MINIMAP_TILE_SIZE) - game->fov.x0))
        {
            game->fov.err += abs((game->fov.end.x / 64.0 * MINIMAP_TILE_SIZE) - game->fov.x0);
            if (game->fov.y0 < game->fov.end.y / 64.0 * MINIMAP_TILE_SIZE)
            	game->fov.y0 += 1;
			else
				game->fov.y0 += -1;
        }
    }
}
void draw_fov_limits(t_game *game)
{
	t_vector	player_pos;
	player_pos.x = 450;
	player_pos.y = 450;

	draw_vector(game, player_pos, game->fov_left, 10000);  // Bord gauche en rouge
	draw_vector(game, player_pos, game->fov_right, 10000); // Bord droit en rouge
}
