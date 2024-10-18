/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:38:58 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/18 12:48:50 by adebert          ###   ########.fr       */
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

void print_int_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		i++;
		printf("%d\n", array[i]);
	}
}


int	print_error(char *error)
{
	printf("%s\n", error);
	return (ERROR);
}

void	error_msg(const char *error)
{
	if (!error)
		return ;
	write(2, error, ft_strlen(error));
}