/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:41:34 by Matprod           #+#    #+#             */
/*   Updated: 2024/12/29 20:26:39 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	vec_rotate(t_vector vector, float angle)
{
	t_vector	output;
	float		cosine;
	float		sine;
	float		x;
	float		y;

	angle = angle * M_PI / 180.0f;
	cosine = cosf(angle);
	sine = sinf(angle);
	x = vector.x * cosine - vector.y * sine;
	y = vector.x * sine + vector.y * cosine;
	output.x = x;
	output.y = y;
	return (output);
}
