/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:35:57 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/03 17:08:10 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
void	free_map(t_map *map)
{
	if (map->map)
		free_array(map->map);
	if (map->text_ea)
		free(map->text_ea);
	if (map->text_no)
		free(map->text_no);
	if (map->text_we)
		free(map->text_we);
	if (map->text_so)
		free(map->text_so);
	if (map->map_name)
		free(map->map_name);
}

void	free_all(t_map *map)
{
	free_map(map);
}