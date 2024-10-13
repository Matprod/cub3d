/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:15:44 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/13 22:12:18 by Matprod          ###   ########.fr       */
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
		printf("Error : Invalid color floor input\n");
		return (ERROR);
	}
	i = -1;
	while (second_split[++i])
		;
	if (i != 3)
	{
		free_array(first_split);
		free_array(second_split);
		printf("Error : Invalid color floor input\n");
		return (ERROR);
	}
	return (SUCCESS);
}

static	bool	split_line_floor(t_map **map, char *line)
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
		{
			free(line);
			return (ERROR);
		}
		while (second_split[++i])
			(*map)->color_floor[i+1] = ft_atoi(second_split[i]);
		free_array(first_split);
		free_array(second_split);
		free(line);
		return (SUCCESS);
	}
	free(line);
	return (ERROR);
}

bool	get_color_floor(t_map **map)
{
	int		fd;
	char	*line;

	fd = open((*map)->map_name, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), ERROR);
	if (!map)
		close_and_free((*map)->map, fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		split_line_floor(map, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (SUCCESS);
}
