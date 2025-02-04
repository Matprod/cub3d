/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:56:32 by Matprod           #+#    #+#             */
/*   Updated: 2024/12/29 20:26:18 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	vec_mult(t_vector vec1, t_vector vec2)
{
	t_vector	mult;

	mult.x = vec1.x * vec2.x;
	mult.y = vec1.y * vec2.y;
	return (mult);
}
