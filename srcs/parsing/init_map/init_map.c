/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:52:56 by allan             #+#    #+#             */
/*   Updated: 2024/10/20 23:51:42 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_map(char *map_name, t_parse **parser)
{
	if (get_map_name(map_name, parser) == ERROR)			//LF
		return (ERROR);
	if (get_map(*parser) == ERROR)							//
		return (ERROR);
	if (get_color_element(*parser, CEILING, 'C') == ERROR)	//
		return (ERROR);
	if (get_color_element(*parser, FLOOR, 'F') == ERROR)	//
		return (ERROR);
	if (get_texture_path(*parser) == ERROR)					//
		return (ERROR);
	(*parser)->map_height = map_height((*parser)->map);
	(*parser)->map_width = map_width((*parser)->map);
	return (SUCCESS);
}
