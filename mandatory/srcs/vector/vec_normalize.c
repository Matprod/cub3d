/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:56:02 by Matprod           #+#    #+#             */
/*   Updated: 2024/12/29 20:26:22 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	vec_normalize(t_vector vec)
{
	float		magnitude;
	t_vector	norm_vec;

	magnitude = sqrt(vec.x * vec.x + vec.y * vec.y);
	if (magnitude == 0)
		return (vec);
	norm_vec.x = vec.x / magnitude;
	norm_vec.y = vec.y / magnitude;
	return (norm_vec);
}
