/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:10:10 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/01 14:22:36 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_map_name(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (i < 5)
	{
		printf("Map name is too short\n");
		return (FALSE);
	}
	if (map[i - 1] != 'b' || map[i - 2] != 'u' || map[i - 3] != 'c'
		|| map[i - 4] != '.')
	{
		printf("Map name is invalid\n");
		return (FALSE);
	}
	return (TRUE);
}

void parsing(char *map_name)
{
	int	fd;

	if (!is_valid_map_name(map_name))
		return ;
	if 
}