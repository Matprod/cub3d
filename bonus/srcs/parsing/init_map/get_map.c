/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:40:37 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/02 15:50:08 by Matprod          ###   ########.fr       */
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
	map->map = (char **)ft_calloc(nb + 1, sizeof(char *));
	if (!map->map)
		return (error_msg(ERROR_MALLOC), close(fd), ERROR);
	if (add_singleton_data(map->map, DOUBLE_PTR) == ERROR)
		return (ERROR);
	nb = 0;
	line = get_next_line(fd, FALSE);
	while (line != NULL)
	{
		if (add_line(map->map, line, &nb) == ERROR)
			return (get_next_line(fd, TRUE), free(line), close(fd), ERROR);
		line = get_next_line(fd, FALSE);
	}
	map->map[nb] = NULL;
	return (close(fd), SUCCESS);
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
	line = get_next_line(fd, FALSE);
	while (line != NULL)
	{
		if (skip_data_map(line) == TRUE)
			nb++;
		free(line);
		line = get_next_line(fd, FALSE);
	}
	return (close(fd), nb);
}

bool	add_line(char **map, char *line, int *nb)
{
	char	**split_eof;

	if (skip_data_map(line) == TRUE)
	{
		split_eof = ft_split(line, '\n');
		map[*nb] = ft_strdup(split_eof[0]);
		if (!map[*nb])
		{
			free_array(split_eof);
			free(line);
			return (error_msg(ERROR_MALLOC), ERROR);
		}
		free_array(split_eof);
		(*nb)++;
	}
	free(line);
	return (SUCCESS);
}

bool	skip_data_map(char *line)
{
	if (line[0] && (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'))
		return (FALSE);
	if (line[0] && (line[0] == 'E' || line[0] == 'F' || line[0] == 'C'))
		return (FALSE);
	return (TRUE);
}

void	close_and_free(char **array, int fd)
{
	free_array(array);
	close(fd);
}
