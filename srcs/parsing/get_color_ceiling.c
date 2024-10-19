/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:51:33 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/19 14:01:05 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	bool	split_line_ceiling(t_parse *map, char *line)
{
	char	**first_split;
	char	**second_split;
	int		i;

	i = -1;
	if (line[0] == 'C')
	{
		first_split = ft_split(line, ' ');
		second_split = ft_split(first_split[1], ',');
		if (check_valid_split(first_split, second_split) == ERROR)
			return (free(line), ERROR);
		while (second_split[++i])
			map->color_ceiling[i+1] = ft_atoi(second_split[i]);
		free_array(first_split);
		free_array(second_split);
		free(line);
		return (SUCCESS);
	}
	free(line);
	return (ERROR);
}

bool	get_color_ceiling(t_parse *map)
{
	int		fd;
	char	*line;

	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		return (error_msg(ERROR_OPEN), ERROR);
	line = get_next_line(fd);
	while (line != NULL)
	{
		split_line_ceiling(map, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (SUCCESS);
}