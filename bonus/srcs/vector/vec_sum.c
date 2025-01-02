/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:54:23 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/15 16:54:28 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	vec_sum(t_vector vec1, t_vector vec2)
{
	t_vector	sum;

	sum.x = vec1.x + vec2.x;
	sum.y = vec1.y + vec2.y;
	return (sum);
}