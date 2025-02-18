/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:46:25 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/18 17:37:11 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_ceiling_and_floor(t_game *game, t_vector line_pos,
			double line_height)
{
	int	i;

	i = -1;
	while (++i < line_pos.y)
	{
		if (!(line_pos.x >= START_MINIMAP_X && line_pos.x
				< START_MINIMAP_X + MINIMAP_SIZE
				&& i >= START_MINIMAP_Y && i < START_MINIMAP_Y + MINIMAP_SIZE))
			img_pix_put(&game->fps_img, line_pos.x, i, game->texture.sky_color);
	}
	i = line_pos.y + line_height;
	while (i < RES_Y)
	{
		if (!(line_pos.x >= START_MINIMAP_X && line_pos.x
				< START_MINIMAP_X + MINIMAP_SIZE
				&& i >= START_MINIMAP_Y && i < START_MINIMAP_Y + MINIMAP_SIZE))
			img_pix_put(&game->fps_img, line_pos.x, i,
				game->texture.floor_color);
		i++;
	}
}

void	render_wall_texture(t_game *game, t_collision collision,
	t_vector line_pos, double line_height)
{
	int	i;
	int	x_text;
	int	y_text;
	int	pixel_color;

	i = 0;
	while (i < line_height)
	{
		x_text = (int)collision.x_pos_tex;
		y_text = (int)((i / line_height) * 64);
		pixel_color = img_pix_read(get_wall_texture(game, collision),
				x_text, y_text);
		if (!(line_pos.x >= START_MINIMAP_X && line_pos.x
				< START_MINIMAP_X + MINIMAP_SIZE
				&& (line_pos.y + i) >= START_MINIMAP_Y && (line_pos.y + i)
				< START_MINIMAP_Y + MINIMAP_SIZE))
			img_pix_put(&game->fps_img, line_pos.x, line_pos.y + i,
				pixel_color);
		i++;
	}
}

void	texture_render(t_game *game, t_collision collision,
		t_vector line_pos, double line_height)
{
	render_ceiling_and_floor(game, line_pos, line_height);
	render_wall_texture(game, collision, line_pos, line_height);
}

void	update_collision(t_collision *collision, t_game *game,
		t_vector line_pos, float half_width)
{
	t_vector	v_player_to_camera_plane;
	t_vector	v_right;

	v_player_to_camera_plane = vec_scalar_mult(game->player.direction,
			game->player.direction_adjust);
	v_right = vec_normalize(vec_rotate(game->player.direction, 90));
	*collision = cast_two_d_ray(game,
			vec_normalize(vec_sum(v_player_to_camera_plane,
					vec_scalar_mult(v_right,
						((2.0f * (float)line_pos.x / (RES_X - 1.0f))
							- 1.0f) * half_width))));
	collision->distance = collision->distance / 64
		* cosf(vec_angle(vec_normalize(vec_sum(v_player_to_camera_plane,
						vec_scalar_mult(v_right, ((2.0f * (float)line_pos.x
									/ (RES_X - 1.0f)) - 1.0f) * half_width))),
				game->player.direction));
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
