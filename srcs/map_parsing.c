/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:40:37 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/03 18:13:23 by Matprod          ###   ########.fr       */
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

static char	*close_and_free(char **array, int fd)
{
	free_array(array);
	close(fd);
	return (NULL);
}

static void	add_line(char **map, char *line, int *nb)
{
	if (skip_data_map(line) == TRUE)
	{
		map[*nb] = ft_strdup(line);
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
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!map)
		close_and_free(map, fd);
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

