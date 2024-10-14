/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:40 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/14 18:12:19 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_parse	*parse;

	parse = malloc(sizeof(t_parse));
	if (!parse)
		return (printf("Error malloc parse\n"), ERROR);
	if (argc != 2)
		return (ERROR);
	if (parsing(argv[1], &parse) == ERROR)
		return (ERROR);
	print_array(parse->map);
	printf("color ceiling =\n");
	print_int_array(parse->color_ceiling, 3);
	printf("color floor =\n");
	print_int_array(parse->color_floor, 3);
	printf("data map text no = %s\n",parse->text_no);
	printf("data map text so = %s\n",parse->text_so);
	printf("data map text ea = %s\n",parse->text_ea);
	printf("data map text we = %s\n",parse->text_we);
	free_all(parse);
	return (SUCCESS);
}
