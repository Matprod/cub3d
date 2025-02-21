/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:22:01 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/21 00:52:03 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	get_texture_path(t_parse *map)
{
	int		fd;
	char	*line;

	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		return (error_msg(ERROR_OPEN), ERROR);
	if (set_default_texture(map) == ERROR)
		return (ERROR);
	line = get_next_line(fd, FALSE);
	while (line != NULL)
	{
		trim_leading_spaces(line);
		if (is_texture(line))
		{
			if (split_line_texture(map, line) == ERROR)
			{
				get_next_line(fd, TRUE);
				return (error_msg("ERROR SPLIT TEXTURE\n"),ERROR);
			}
		}
		free(line);
		line = get_next_line(fd, FALSE);
	}
	close(fd);
	return (SUCCESS);
}

bool	set_default_texture(t_parse *map)
{
	map->text_no = ft_strdup(NORTH_WALL);
	if (!map->text_no)
		return (ERROR);
	if (add_singleton_data(map->text_no, SINGLE_PTR) == ERROR)
		return (ERROR);
	map->text_so = ft_strdup(SOUTH_WALL);
	if (!map->text_so)
		return (ERROR);
	if (add_singleton_data(map->text_so, SINGLE_PTR) == ERROR)
		return (ERROR);
	map->text_ea = ft_strdup(EAST_WALL);
	if (!map->text_ea)
		return (ERROR);
	if (add_singleton_data(map->text_ea, SINGLE_PTR) == ERROR)
		return (ERROR);
	map->text_we = ft_strdup(WEST_WALL);
	if (!map->text_we)
		return (ERROR);
	if (add_singleton_data(map->text_we, SINGLE_PTR) == ERROR)
		return (ERROR);
	return (SUCCESS);
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

bool	split_line_texture(t_parse *map, char *line)
{
	char	**split;
	char	**split_eof;

	split = ft_split(line, ' ');
	split_eof = ft_split(split[1], '\n');
	if (check_split_texture(split, line) == ERROR)
		return (free_array(split_eof), ERROR);
	if (line[0] == 'N' && line[1] == 'O')
	{	
		map->text_no = ft_strdup(split_eof[0]);
		if (add_singleton_data(map->text_no, SINGLE_PTR) == ERROR)
			return (free_array(split), free_array(split_eof), ERROR);
	}
	if (line[0] == 'S' && line[1] == 'O')
	{
		map->text_so = ft_strdup(split_eof[0]);
		if (add_singleton_data(map->text_so, SINGLE_PTR) == ERROR)
			return (free_array(split), free_array(split_eof), ERROR);
	}
	if (line[0] == 'E' && line[1] == 'A')
	{
		map->text_ea = ft_strdup(split_eof[0]);
		if (add_singleton_data(map->text_ea, SINGLE_PTR) == ERROR)
			return (free_array(split), free_array(split_eof), ERROR);
	}
	if (line[0] == 'W' && line[1] == 'E')
	{
		map->text_we = ft_strdup(split_eof[0]);
		if (add_singleton_data(map->text_we, SINGLE_PTR) == ERROR)
			return (free_array(split), free_array(split_eof), ERROR);
	}
	free_array(split);
	free_array(split_eof);
	return (SUCCESS);
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
