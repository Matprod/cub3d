/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate_rad.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:54:55 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/15 16:54:58 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vec_rotate_rad(t_vector *vector, float angle)
{
	float	cosine;
	float	sine;
	float	x;
	float	y;

	cosine = cosf(angle);
	sine = sinf(angle);
	x = vector->x * cosine - vector->y * sine;
	y = vector->x * sine + vector->y * cosine;
	vector->x = x;
	vector->y = y;
}