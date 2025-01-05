/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morty_gif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:25:13 by Matprod           #+#    #+#             */
/*   Updated: 2025/01/02 23:05:04 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void load_morty_img(t_game *game)
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
		{
			game->texture.morty[i] = create_img(game, current);
			if (!game->texture.morty[i].mlx_img)
			{
				printf("Erreur : Impossible de charger texture.morty[%d] (%s)\n", i, current);
				free(current);
				return;
			}
		}
		else
		{
			printf("Erreur : Fichier non trouvé ( %s )\n", current);
			free(current);
			return;
		}
		free(current);
		i++;
	}
}
