/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:01:30 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/13 22:10:22 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

typedef struct s_int
{
	int array1[3];
	int array2[3];
}	t_int;

void	modif_array(t_int *stock)
{
	(stock)->array1[1] = 1;
	(stock)->array1[2] = 2;
	(stock)->array1[3] = 3;
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

int main(void)
{
	t_int *stock;

	stock = malloc(sizeof(t_int));
	modif_array(stock);
	print_int_array(stock->array1, 3);

}