/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:40:37 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/18 12:58:59 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	skip_data_map(char *line)
{
	if (line[0] && (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'))
		return (FALSE);
	if (line[0] && (line[0] == 'E' || line[0] == 'F' || line[0] == 'C'))
		return (FALSE);
	return (TRUE);
}

static int	get_nb_line_fd(char *map_name)
{
	int		fd;
	char	*line;
	int		nb;

	nb = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (0);
	}
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

void	close_and_free(char **array, int fd)
{
	free_array(array);
	close(fd);
}

static void	add_line(char **map, char *line, int *nb)
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

char	**get_map(char *map_name)
{
	int		fd;
	int		nb;
	char	*line;
	char	**map;

	nb = get_nb_line_fd(map_name);
	if (nb == 0)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (error_msg(ERROR_OPEN), NULL);
	map = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!map)
		return (error_msg(ERROR_MALLOC), close_and_free(map, fd), NULL);
	nb = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		add_line(map, line, &nb);
		line = get_next_line(fd);
	}
	map[nb] = NULL;
	close(fd);
	return (map);
}

