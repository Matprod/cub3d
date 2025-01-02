/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_to_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:53:48 by Matprod           #+#    #+#             */
/*   Updated: 2024/12/29 20:26:49 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vec_to_angle(double angle, t_vector *vector)
{
	double	magnitude;

	vector->x = cos(angle);
	vector->y = sin(angle);
	magnitude = sqrt(pow(vector->x, 2) + pow(vector->y, 2));
	vector->x /= magnitude;
	vector->y /= magnitude;
}
