/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:07:52 by Matprod           #+#    #+#             */
/*   Updated: 2024/12/29 20:29:42 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_filled_circle(t_img *img, t_vector mid, int radius, int color)
{
	int	x;
	int	y;

	x = mid.x - radius;
	while (++x < mid.x + radius)
	{
		y = mid.y - radius;
		while (++y < mid.y + radius)
			if (pow(x - mid.x, 2) + pow(y - mid.y, 2) <= pow(radius, 2))
				img_pix_put(img, x, y, color);
	}
}
