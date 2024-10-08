/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:38:58 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/07 18:57:52 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_array(char **array)
{
	int i;

	i = 0;
	while(array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}

void	print_int_array(int **array)
{
	int i;

	i = 0;
	while(array[i])
	{
		printf("%d\n", array[i]);
		i++;
	}
}

int	print_error(char *error)
{
	printf("%s\n", error);
	return (ERROR);
}