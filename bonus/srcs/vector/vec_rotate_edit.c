/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate_edit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:55:12 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/15 16:55:20 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vec_rotate_edit(t_vector *vector, float angle)
{
	float	cosine;
	float	sine;
	float	x;
	float	y;

	angle = angle * M_PI / 180.0f;
	cosine = cosf(angle);
	sine = sinf(angle);
	x = vector->x * cosine - vector->y * sine;
	y = vector->x * sine + vector->y * cosine;
	vector->x = x;
	vector->y = y;
}