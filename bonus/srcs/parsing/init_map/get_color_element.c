/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:49:49 by allan             #+#    #+#             */
/*   Updated: 2025/02/21 00:56:45 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	get_color_element(t_parse *map, int element, char name)
{
	int		fd;
	char	*line;

	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		return (error_msg(ERROR_OPEN), ERROR);
	line = get_next_line(fd, FALSE);
	while (line != NULL)
	{
		trim_leading_spaces(line);
		if (split_line(map, line, element, name) == ERROR)
		{
			get_next_line(fd, TRUE);
			return (free(line), close(fd), error_msg(ERROR_MALLOC), ERROR);
		}
		line = get_next_line(fd, FALSE);
	}
	close(fd);
	return (SUCCESS);
}

bool	split_line(t_parse *map, char *line, int element, char name)
{
	char	**first_split;
	char	**second_split;
	int		color_element[3];
	int		i;

	i = -1;
	if (line[0] == name)
	{
		first_split = ft_split(line, ' ');
		if (!first_split)
			return (ERROR);
		second_split = ft_split(first_split[1], ',');
		if (!second_split)
			return (free_array(first_split), ERROR);
		if (check_valid_split(first_split, second_split, element) == ERROR)
			return (free_array(first_split), free_array(second_split), ERROR);
		while (second_split[++i])
			color_element[i] = ft_atoi(second_split[i]);
		copy_color(color_element, map, element);
		free_array(first_split);
		free_array(second_split);
		return (free(line), SUCCESS);
	}
	return (free(line), NOT_FOUND);
}

bool	check_valid_split(char **first_split, char **second_split,
				int element)
{
	int	i;

	i = -1;
	while (first_split[++i])
		;
	if (i != 2)
	{
		free_array(first_split);
		free_array(second_split);
		return (error_color(element), ERROR);
	}
	i = -1;
	while (second_split[++i])
		;
	if (i != 3)
	{
		free_array(first_split);
		free_array(second_split);
		return (error_color(element), ERROR);
	}
	return (SUCCESS);
}

void	copy_color(int color_element[3], t_parse *map, int element)
{
	if (element == CEILING)
		ft_memcpy(map->color_ceiling, color_element, 3 * sizeof(int));
	else if (element == FLOOR)
		ft_memcpy(map->color_floor, color_element, 3 * sizeof(int));
}

void	error_color(int element)
{
	if (element == CEILING)
		error_msg(ERROR_CEILING_COLOR);
	else if (element == FLOOR)
		error_msg(ERROR_FLOOR_COLOR);
}
