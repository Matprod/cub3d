/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_angle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:13:51 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/15 17:13:54 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	vec_angle(t_vector v1, t_vector v2)
{
	double	dot_product;
	double	magnitude1;
	double	magnitude2;
	double	cos_theta;

	dot_product = v1.x * v2.x + v1.y * v2.y;
	magnitude1 = sqrt(v1.x * v1.x + v1.y * v1.y);
	magnitude2 = sqrt(v2.x * v2.x + v2.y * v2.y);
	cos_theta = dot_product / (magnitude1 * magnitude2);
	return (acosf(cos_theta));
}