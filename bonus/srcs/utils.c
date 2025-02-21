/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:49:29 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/21 12:37:51 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

void	trim_leading_spaces(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && ft_isspace((unsigned char)str[i]))
		i++;
	while (str[i])
		str[j++] = str[i++];
	str[j] = '\0';
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

void	free_two_array(char **first_split, char **second_split)
{
	free_array(first_split);
	free_array(second_split);
}

void	copy_color(int color_element[3], t_parse *map, int element)
{
	if (element == CEILING)
		ft_memcpy(map->color_ceiling, color_element, 3 * sizeof(int));
	else if (element == FLOOR)
		ft_memcpy(map->color_floor, color_element, 3 * sizeof(int));
}