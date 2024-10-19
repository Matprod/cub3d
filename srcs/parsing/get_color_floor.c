/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:15:44 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/19 14:00:41 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	bool	split_line_floor(t_parse *map, char *line)
{
	char	**first_split;
	char	**second_split;
	int		i;

	i = -1;
	if (line[0] == 'F')
	{
		first_split = ft_split(line, ' ');
		second_split = ft_split(first_split[1], ',');
		if (check_valid_split(first_split, second_split) == ERROR)
			return (free(line), ERROR);
		while (second_split[++i])
			map->color_floor[i+1] = ft_atoi(second_split[i]);
		free_array(first_split);
		free_array(second_split);
		free(line);
		return (SUCCESS);
	}
	free(line);
	return (NOT_FOUND);
}

bool	get_color_floor(t_parse *map)
{
	int		fd;
	char	*line;

	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		return (error_msg(ERROR_OPEN), ERROR);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (split_line_floor(map, line) == ERROR)
			return (ERROR);
		line = get_next_line(fd);
	}
	close(fd);
	return (SUCCESS);
}
