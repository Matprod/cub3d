/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:22:01 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/09 15:13:00 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:51:33 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/09 14:21:42 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_texture(char *line)
{
	if (ft_strlen(line) < 2)
		return (FALSE);
	if (line[0] == 'N' && line[1] == 'O')
		return (TRUE);
	if (line[0] == 'S' && line[1] == 'O')
		return (TRUE);
	if (line[0] == 'W' && line[1] == 'E')
		return (TRUE);
	if (line[0] == 'E' && line[1] == 'A')
		return (TRUE);
	return (FALSE);
}

static	bool	check_valid_split(char **split, char *line)
{
	int	i;

	i = -1;
	while (split[++i])
		;
	if (i != 2)
	{
		free(line);
		free_array(split);
		printf("Error : Invalid texture path input\n");
		return (ERROR);
	}
	/* if (open(split[1], O_RDONLY) == -1)
	{
		free(line);
		free_array(split);
		return (perror("Error opening file"), ERROR);
	} */
	return (SUCCESS);
}

static	bool	split_line_texture(t_map *map, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (check_valid_split(split, line) == ERROR)
		return (ERROR);
	if (line[0] == 'N' && line[1] == 'O')
		map->text_no = ft_strdup(split[1]);
	if (line[0] == 'S' && line[1] == 'O')
		map->text_so = ft_strdup(split[1]);
	if (line[0] == 'E' && line[1] == 'A')
		map->text_ea = ft_strdup(split[1]);
	if (line[0] == 'W' && line[1] == 'E')
		map->text_we = ft_strdup(split[1]);
	free_array(split);
	return (SUCCESS);
}

bool	get_texture_path(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), ERROR);
	if (!map)
		close_and_free(map->map, fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_texture(line))
			split_line_texture(map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (SUCCESS);
}
