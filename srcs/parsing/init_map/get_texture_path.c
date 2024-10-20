/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:22:01 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/20 18:38:23 by allan            ###   ########.fr       */
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

void	init_texture(t_parse *data_map)
{
	data_map->text_no = NULL;
	data_map->text_so = NULL;
	data_map->text_ea = NULL;
	data_map->text_we = NULL;
	if (!data_map->text_no)
		data_map->text_no = ft_strdup(NORTH_WALL);
	if (!data_map->text_so)
		data_map->text_so = ft_strdup(SOUTH_WALL);
	if (!data_map->text_ea)
		data_map->text_ea = ft_strdup(EAST_WALL);
	if (!data_map->text_we)
		data_map->text_we = ft_strdup(WEST_WALL);
}

bool	is_texture(char *line)
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

bool	check_split_texture(char **split, char *line)
{
	int	i;

	i = -1;
	while (split[++i])
		;
	if (i != 2)
	{
		free(line);
		free_array(split);
		return (error_msg(ERROR_TEXTURE_PATH), ERROR);
	}
	return (SUCCESS);
}

bool	split_line_texture(t_parse *map, char *line)
{
	char	**split;
	char	**split_eof;

	split = ft_split(line, ' ');
	split_eof = ft_split(split[1], '\n');
	if (check_split_texture(split, line) == ERROR)
		return (ERROR);
	if (line[0] == 'N' && line[1] == 'O')
		map->text_no = ft_strdup(split_eof[0]);
	if (line[0] == 'S' && line[1] == 'O')
		map->text_so = ft_strdup(split_eof[0]);
	if (line[0] == 'E' && line[1] == 'A')
		map->text_ea = ft_strdup(split_eof[0]);
	if (line[0] == 'W' && line[1] == 'E')
		map->text_we = ft_strdup(split_eof[0]);
	free_array(split);
	free_array(split_eof);
	return (SUCCESS);
}

bool	get_texture_path(t_parse *map)
{
	int		fd;
	char	*line;

	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		return (error_msg(ERROR_OPEN), ERROR);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_texture(line))
			split_line_texture(map, line);
		free(line);
		line = get_next_line(fd);
	}
	init_texture(map);
	close(fd);
	return (SUCCESS);
}