/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:40:37 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/20 16:17:10 by allan            ###   ########.fr       */
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
		return (error_msg(ERROR_MAP_CONTENT), ERROR);
	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		return (error_msg(ERROR_OPEN), ERROR);
	map->map = (char **)ft_calloc(nb + 1, sizeof(char *));
	if (!map->map)
		return (error_msg(ERROR_MALLOC), close(fd), ERROR);
	if (add_singleton_data(map->map, DOUBLE_PTR) == ERROR)
		return (error_msg(ERROR_MALLOC), ERROR);
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
	bool	map_started;

	map_started = FALSE;
	nb = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (error_msg(ERROR_OPEN), 0);
	line = get_next_line(fd, FALSE);
	while (line != NULL)
	{
		if (skip_data_map(line) == FALSE)
		{
			nb++;
			map_started = TRUE;
		}
		else if (skip_data_map(line) == TRUE && map_started == TRUE)
			return (get_next_line(fd, TRUE),
				free(line), close(fd), 0);
		free(line);
		line = get_next_line(fd, FALSE);
	}
	return (close(fd), nb);
}

bool	skip_data_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] && (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'))
		return (TRUE);
	if (line[i] && (line[i] == 'E' || line[i] == 'F' || line[i] == 'C'))
		return (TRUE);
	if (line[i] && (line[i] == '\n'))
		return (TRUE);
	return (FALSE);
}

bool	add_line(char **map, char *line, int *nb)
{
	char	**split_eof;

	if (skip_data_map(line) == FALSE)
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

void	close_and_free(char **array, int fd)
{
	free_array(array);
	close(fd);
}
