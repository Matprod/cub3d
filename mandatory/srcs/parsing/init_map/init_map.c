/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:52:56 by allan             #+#    #+#             */
/*   Updated: 2025/02/20 20:04:33 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_map(char *map_name, t_parse **parser)
{
	if (get_map_name(map_name, parser) == ERROR)
		return (ERROR);
	if (get_map(*parser) == ERROR)
		return (ERROR);
	if (get_color_element(*parser, CEILING, 'C') == ERROR)
		return (ERROR);
	if (get_color_element(*parser, FLOOR, 'F') == ERROR)
		return (ERROR);
	if (get_texture_path(*parser) == ERROR)
		return (ERROR);
	if (open((*parser)->text_no, 1) == -1)
		return (error_msg("Error\nThis path don't exist\n"), ERROR);
	if (open((*parser)->text_so, 1) == -1)
		return (error_msg("Error\nThis path don't exist\n"), ERROR);
	if (open((*parser)->text_ea, 1) == -1)
		return (error_msg("Error\nThis path don't exist\n"), ERROR);
	if (open((*parser)->text_we, 1) == -1)
		return (error_msg("Error\nThis path don't exist\n"), ERROR);
	(*parser)->map_height = map_height((*parser)->map);
	(*parser)->map_width = map_width((*parser)->map);
	return (SUCCESS);
}
