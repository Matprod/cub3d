/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:10:10 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/20 19:22:14 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parser(char *map_name, t_parse **parser)
{
	if (init_map(map_name, parser) == ERROR)
		return (ERROR);
	if (check_map(*parser) == ERROR)
		return (free_map(*parser), ERROR);
	return (SUCCESS);
}
