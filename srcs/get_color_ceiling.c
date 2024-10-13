/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:51:33 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/13 22:11:40 by Matprod          ###   ########.fr       */
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
		printf("Error : Invalid color ceiling input\n");
		return (ERROR);
	}
	i = -1;
	while (second_split[++i])
		;
	if (i != 3)
	{
		free_array(first_split);
		free_array(second_split);
		printf("Error : Invalid color ceiling input\n");
		return (ERROR);
	}
	return (SUCCESS);
}

static	bool	split_line_ceiling(t_map **map, char *line)
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
		{
			free(line);
			return (ERROR);
		}
		while (second_split[++i])
		{
			(*map)->color_ceiling[i+1] = ft_atoi(second_split[i]);
		}
		free_array(first_split);
		free_array(second_split);
		free(line);
		return (SUCCESS);
	}
	free(line);
	return (ERROR);
}

bool	get_color_ceiling(t_map **map)
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
		split_line_ceiling(map, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (SUCCESS);
}