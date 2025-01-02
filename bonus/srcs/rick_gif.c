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
    int     i;
    char    *current;
    char    *temp;

    char *start = "./images/morty/frame_00";
    char *final = ".xpm";
    i = 0;

    while (i < MORTY_FRAMES)
    {
        temp = ft_strjoin(start, ft_itoa(i)); // Exemple : "./images/morty/frame1"
        current = ft_strjoin(temp, final);    // Exemple : "./images/morty/frame1.xpm"
        free(temp); // Libère la mémoire temporaire utilisée par ft_itoa

        // Charger l'image
        if (access(current, F_OK) == 0) // Vérifie que le fichier existe
        {
            game->texture.morty[i] = create_img(game, current);
            if (!game->texture.morty[i].mlx_img) // Vérifie si l'image est bien créée
            {
                printf("Erreur : Impossible de charger texture.morty[%d] (%s)\n", i, current);
                free(current);
                return; // Quitte en cas d'erreur
            }
        }
        else
        {
            printf("Erreur : Fichier non trouvé ( %s )\n", current);
            free(current);
            return; // Quitte en cas d'erreur
        }

        free(current); // Libère le chemin actuel
        i++;
    }
}
