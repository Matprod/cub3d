/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:01:04 by Matprod           #+#    #+#             */
/*   Updated: 2024/11/10 00:16:26 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast_two(t_game *game, t_raycast_data *d)
{
	if (d->v_ray_dir.y < 0)
	{
		d->v_step.y = -1;
		d->v_ray_length_1d.y = (game->player.pos.y
				- tile_to_pixel(d->v_map_check).y) / 64 * d->v_ray_unit_step.y;
	}
	else
	{
		d->v_step.y = 1;
		d->v_ray_length_1d.y = (tile_to_pixel(d->v_map_check).y + 64
				- game->player.pos.y) / 64 * d->v_ray_unit_step.y;
	}
}

void	init_raycast(t_game *game, t_vector direction, t_raycast_data *d)
{
	// Pré-calcul des positions du joueur et du carreau en coordonnées pixels
	t_vector player_pos = game->player.pos;
	t_vector map_check_pixel = tile_to_pixel(pixel_to_tile(player_pos));
	
	d->v_map_check = pixel_to_tile(player_pos);
	d->v_ray_dir = direction;

	// Calcul des étapes en une seule opération, évitant les divisions répétées
	float inv_dir_x = (d->v_ray_dir.x != 0) ? 1.0f / d->v_ray_dir.x : 0;
	float inv_dir_y = (d->v_ray_dir.y != 0) ? 1.0f / d->v_ray_dir.y : 0;

	d->v_ray_unit_step.x = sqrt(1 + (d->v_ray_dir.y * inv_dir_x) * (d->v_ray_dir.y * inv_dir_x));
	d->v_ray_unit_step.y = sqrt(1 + (d->v_ray_dir.x * inv_dir_y) * (d->v_ray_dir.x * inv_dir_y));

	// Calcul direct de `v_step` et `v_ray_length_1d`
	d->v_step.x = (d->v_ray_dir.x < 0) ? -1 : 1;
	d->v_ray_length_1d.x = ((d->v_ray_dir.x < 0 ? player_pos.x - map_check_pixel.x
									: map_check_pixel.x + 64 - player_pos.x)
							* inv_dir_x) * d->v_ray_unit_step.x;

	d->v_step.y = (d->v_ray_dir.y < 0) ? -1 : 1;
	d->v_ray_length_1d.y = ((d->v_ray_dir.y < 0 ? player_pos.y - map_check_pixel.y
									: map_check_pixel.y + 64 - player_pos.y)
							* inv_dir_y) * d->v_ray_unit_step.y;
							
	init_raycast_two(game, d);
}


void	fill_collision(t_raycast_data *d, char last_step)
{
	d->collision.distance = d->distance * 64;
	d->collision.orientation = get_collision_orientation(last_step, d->v_step);
	d->collision.x_pos_tex = get_texture_x(last_step, d->collision_point,
			d->v_map_check);
}

void	make_step(t_raycast_data *d)
{
	if (d->v_ray_length_1d.x < d->v_ray_length_1d.y)
	{
		d->last_step = 'x';
		d->v_map_check.x += d->v_step.x;
		d->distance = d->v_ray_length_1d.x;
		d->v_ray_length_1d.x += d->v_ray_unit_step.x;
	}
	else
	{
		d->last_step = 'y';
		d->v_map_check.y += d->v_step.y;
		d->distance = d->v_ray_length_1d.y;
		d->v_ray_length_1d.y += d->v_ray_unit_step.y;
	}
}

t_collision	cast_two_d_ray(t_game *game, t_vector direction)
{
	t_raycast_data	d;
	int				tile_found;

	tile_found = 0;
	d.distance = 0;
	init_raycast(game, direction, &d);
	while (!tile_found)
	{
		make_step(&d);
		d.collision_point = vec_scalar_mult(d.v_ray_dir, d.distance * 64);
		d.collision_point = vec_sum(d.collision_point, game->player.pos);
		if (game->map[(int)d.v_map_check.y][(int)d.v_map_check.x] == '1')
			tile_found = 1;
	}
	fill_collision(&d, d.last_step);
	return ((d.collision));
}