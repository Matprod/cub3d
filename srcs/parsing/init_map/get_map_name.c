/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:13:56 by allan             #+#    #+#             */
/*   Updated: 2024/10/20 19:15:19 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	get_map_name(char *map_name, t_parse **parser)
{
	if (is_valid_map_name(map_name) == FALSE)
		return (free(*parser), ERROR);
	(*parser)->pos_player = (t_vector){0, 0};
	(*parser)->dir_player = 0;
	(*parser)->map_name = ft_strdup(map_name);
	if (!(*parser)->map_name)
		return (error_msg(ERROR_MALLOC), free(*parser), ERROR);
	return (SUCCESS);
}

bool	is_valid_map_name(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (i < 5)
		return (error_msg(ERROR_MAP_NAME), FALSE);
	if (map[i - 4] != '.' || map[i - 3] != 'c'
		|| map[i - 2] != 'u' || map[i - 1] != 'b') //ft_strcmp?
		return (error_msg(ERROR_MAP_FORMAT), FALSE);
	return (TRUE);
}