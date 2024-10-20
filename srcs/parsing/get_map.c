/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:40:37 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/20 18:35:08 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	get_map(t_parse *map)
{
	int		fd;
	int		nb;
	char	*line;

	nb = get_nb_line_fd(map->map_name);
	if (nb == 0)
		return (ERROR);
	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		return (error_msg(ERROR_OPEN), ERROR);
	map->map = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!map->map)
		return (error_msg(ERROR_MALLOC), close_and_free(map->map, fd), ERROR);
	nb = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		add_line(map->map, line, &nb);
		line = get_next_line(fd);
	}
	map->map[nb] = NULL;
	close(fd);
	return (SUCCESS);
}

int	get_nb_line_fd(char *map_name)
{
	int		fd;
	char	*line;
	int		nb;

	nb = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (error_msg(ERROR_OPEN), 0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (skip_data_map(line) == TRUE)
			nb++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nb);
}

bool	skip_data_map(char *line)
{
	if (line[0] && (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'))
		return (FALSE);
	if (line[0] && (line[0] == 'E' || line[0] == 'F' || line[0] == 'C'))
		return (FALSE);
	return (TRUE);
}

void	add_line(char **map, char *line, int *nb)
{
	char **split_eof;

	if (skip_data_map(line) == TRUE)
	{
		split_eof = ft_split(line, '\n');
		map[*nb] = ft_strdup(split_eof[0]);
		free_array(split_eof);
		(*nb)++;
	}
	free(line);
}

void	close_and_free(char **array, int fd)
{
	free_array(array);
	close(fd);
}
