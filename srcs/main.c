/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:40 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/13 20:32:07 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map	*data_map;

	data_map = malloc(sizeof(t_map));
	if (argc != 2)
		return (ERROR);
	if (parsing(argv[1], &data_map) == ERROR)
		return (ERROR);
	//print_array(data_map->map);
	printf("color ceiling =\n");
	print_int_array(data_map->color_ceiling, 3);
	printf("color floor =\n");
	print_int_array(data_map->color_floor, 3);
	printf("data map text no = %s\n",data_map->text_no);
	printf("data map text so = %s\n",data_map->text_so);
	printf("data map text ea = %s\n",data_map->text_ea);
	printf("data map text we = %s\n",data_map->text_we);
	free_all(data_map);
	return (SUCCESS);
}