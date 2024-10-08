/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:15:44 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/07 17:50:39 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	bool	check_valid_split(char **first_split, char **second_split)
{
	int	i;

	i = -1;
	while (first_split[++i])
		;
	if (i != 2)
	{
		free_array(first_split);
		free_array(second_split);
		return (ERROR);
	}
	i = -1;
	while (second_split[++i])
		;
	if (i != 3)
	{
		free_array(first_split);
		free_array(second_split);
		return (ERROR);
	}
	return (SUCCESS);
}

static	bool	get_color_floor(t_map *map, char *line)
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
			return (ERROR);
		while (second_split[++i])
			map->color_floor[i] = ft_atoi(second_split[i]);
		free_array(first_split);
		free_array(second_split);
		return (SUCCESS);
	}
	return (ERROR);
}

bool	read_color_floor(t_map *map)
{
	int		fd;
	int		nb;
	char	*line;

	if (nb == 0)
		return (NULL);
	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), ERROR);
	if (!map)
		close_and_free(map, fd);
	nb = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (get_color_floor(map, line) == SUCCESS)
			break;
	}
	close(fd);
	return (SUCCESS);
}
