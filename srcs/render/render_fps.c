/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:46:25 by Matprod           #+#    #+#             */
/*   Updated: 2024/11/10 12:44:37 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*get_wall_texture(t_game *game, t_collision collision)
{
	if (collision.orientation == 'N')
		return (&game->texture.north);
	else if (collision.orientation == 'S')
		return (&game->texture.south);
	else if (collision.orientation == 'E')
		return (&game->texture.east);
	else if (collision.orientation == 'W')
		return (&game->texture.west);
	return (NULL);
}

void	texture_render(t_game *game, t_collision collision, t_vector line_pos,
		double line_height)
{
	int	i;
	int	x_text;
	int	y_text;
	int	pixel_color;

	i = -1;
	x_text = 0;
	y_text = 0;
	while (++i < line_pos.y)
		img_pix_put(&game->fps_img, line_pos.x, i, game->texture.sky_color);
	i = line_pos.y + line_height;
	while (i < RES_Y)
		img_pix_put(&game->fps_img, line_pos.x, i++,
			game->texture.floor_color);
	i = 0;
	while (i < line_height)
	{
		x_text = (int)collision.x_pos_tex;
		y_text = (int)((i / line_height) * 64);
		pixel_color = img_pix_read(get_wall_texture(game, collision), x_text,
				y_text);
		img_pix_put(&game->fps_img, line_pos.x, line_pos.y + i, pixel_color);
		i++;
	}
}

void	update_collision(t_collision *collision, t_game *game,
		t_vector line_pos, float half_width)
{
	// Calcul des vecteurs pour la direction du joueur et à droite
	t_vector v_player_to_camera_plane = vec_scalar_mult(game->player.direction,
			game->player.direction_adjust);
	t_vector v_right = vec_rotate(game->player.direction, 90); // Rotation de 90 degrés sans normalisation

	// Optimiser l'offset une seule fois pour chaque ligne
	float offset = (2.0f * (float)line_pos.x / (RES_X - 1.0f)) - 1.0f;

	// Calcul direct de la direction du rayon sans appel à vec_sum
	t_vector ray_dir = vec_sum(v_player_to_camera_plane,
		vec_scalar_mult(v_right, offset * half_width));

	// Normalisation directe de ray_dir
	float ray_dir_length = sqrtf(ray_dir.x * ray_dir.x + ray_dir.y * ray_dir.y);
	ray_dir.x /= ray_dir_length;
	ray_dir.y /= ray_dir_length;

	// Lancer du rayon et récupération de la collision
	*collision = cast_two_d_ray(game, ray_dir);

	// Calcul de la distance avec approximation du cosinus sans appel coûteux
	float ray_cos_angle = (ray_dir.x * game->player.direction.x + ray_dir.y * game->player.direction.y);
	collision->distance = collision->distance / 64 * ray_cos_angle;
}

void	render_fps(t_game *game)
{
	int			i;
	float		line_height;
	t_collision	collision;
	t_vector	line_pos;
	float		half_width;

	half_width = tanf((float)FOV_RADIANS / 2.0f)
		* game->player.direction_adjust;
	line_pos.x = 0;
	i = -1;
	while (++i < RES_X)
	{
		update_collision(&collision, game, line_pos, half_width);
		line_height = (64 / collision.distance) * game->player.direction_adjust;
		line_pos.y = RES_Y / 2 - line_height / 2;
		texture_render(game, collision, line_pos, line_height);
		line_pos.x += 1;
	}
}
