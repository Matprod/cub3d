/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rick_gif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:25:13 by Matprod           #+#    #+#             */
/*   Updated: 2025/01/02 21:43:01 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_rick_img(t_game *game)
{
	int	i;
	char *start;
	char *final;
	char *current;

	start = "./images/rick/frame";
	final = ".png";
	i = 1;
	while (i <= RICK_FRAMES)
	{
		current = ft_strjoin(start, ft_itoa(i));
		current = ft_strjoin(start, final);
		game->texture.rick[i] = create_img(game, current);
		if (!game->texture.north.mlx_img)
			return (printf("Error loading texture.rick[%d]\n", i), (void)0);
		i++;
		free(current);
	}
}