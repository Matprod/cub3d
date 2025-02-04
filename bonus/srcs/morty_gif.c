/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morty_gif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:40:33 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/04 16:48:34 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_morty_img(t_game *game)
{
	int		i;
	char	*current;
	char	*temp;
	char	*itoa;

	i = 0;
	while (i < MORTY_FRAMES)
	{
		itoa = ft_itoa(i);
		temp = ft_strjoin(MORTY_START_PATH, itoa);
		free(itoa);
		current = ft_strjoin(temp, FORMAT_XPM);
		free(temp);
		if (access(current, F_OK) == 0)
			game->texture.morty[i] = create_img(game, current);
		free(current);
		i++;
	}
}
