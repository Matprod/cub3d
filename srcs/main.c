/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:40 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/07 18:58:09 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map	*data_map;

	data_map = NULL;
	if (argc != 2)
		return (ERROR);
	if (parsing(argv[1], &data_map) == ERROR)
		return (ERROR);
	//print_array(data_map->map);
	print
	free_all(data_map);
	return (SUCCESS);
}