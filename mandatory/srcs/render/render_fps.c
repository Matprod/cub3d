/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:46:25 by Matprod           #+#    #+#             */
/*   Updated: 2024/12/29 20:24:37 by Matprod          ###   ########.fr       */
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
	while (++i < line_pos.y)
		img_pix_put(&game->fps_img, line_pos.x, i, game->texture.sky_color);
	i = line_pos.y + line_height;
	while (i < RES_Y)
	{
		img_pix_put(&game->fps_img, line_pos.x, i, game->texture.floor_color);
		i++;
	}
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
	t_vector	camera_plane;
	t_vector	right;
	t_vector	ray_dir;
	float		screen_ratio;

	screen_ratio = (2.0f * (float)line_pos.x / (RES_X - 1.0f)) - 1.0f;
	camera_plane = vec_scalar_mult(game->player.direction,
			game->player.direction_adjust);
	right = vec_normalize(vec_rotate(game->player.direction, 90));
	ray_dir = vec_normalize(vec_sum(camera_plane, vec_scalar_mult(right,
					screen_ratio * half_width)));
	*collision = cast_two_d_ray(game, ray_dir);
	collision->distance = (collision->distance / 64) * cosf(vec_angle(ray_dir,
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
