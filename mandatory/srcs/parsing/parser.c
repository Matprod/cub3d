/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:10:10 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/19 19:28:20 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*
*parser


*/
bool	parser(char *map_name, t_parse **parser)
{
	*parser = malloc(sizeof(t_parse));
	if (!(*parser))
		return (error_msg(ERROR_MALLOC), ERROR);
	if (add_singleton_data(*parser, SINGLE_PTR) == ERROR)
		return (ERROR);
	if (init_map(map_name, parser) == ERROR)
		return (ERROR);
	if (check_map(*parser) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
