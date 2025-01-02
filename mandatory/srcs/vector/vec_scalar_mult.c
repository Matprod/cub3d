/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scalar_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:54:36 by Matprod           #+#    #+#             */
/*   Updated: 2024/12/29 20:26:43 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	vec_scalar_mult(t_vector vec1, double i)
{
	t_vector	mult;

	mult.x = vec1.x * i;
	mult.y = vec1.y * i;
	return (mult);
}
