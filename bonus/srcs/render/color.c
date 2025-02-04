/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:43:37 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/04 16:32:01 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(t_img *img, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int *)(img->addr + (4 * (int)img->width * ((int)img->height - 1
					- y)) + (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

unsigned int	img_pix_read(t_img *img, int x, int y)
{
	char	*pixel;

	if (pixel_out_of_bound(x, y, img))
		return (0);
	pixel = (img->addr + (y * img->line_len + x * (img->bpp / 8)));
	return (*(unsigned int *)pixel);
}
