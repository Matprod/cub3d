/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:36:31 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/14 17:36:44 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_height(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		;
	return (i);
}

int	map_width(char **map)
{
	int	i;
	int	max;

	i = -1;
	max = 0;
	while (map[++i])
	{
		if ((int)ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
	}
	return (max);
}