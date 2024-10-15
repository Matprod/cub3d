/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:57:04 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/15 15:44:41 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window(game);
	if (keycode == 'w' || keycode == 'a' || keycode == 'd' || keycode == 's'
		|| keycode == 'r' || keycode == 'f')
		game->key_states[keycode] = 1;
	if (keycode == RIGHT)
		game->key_states[0] = 1;
	if (keycode == LEFT)
		game->key_states[1] = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == 'w' || keycode == 'a' || keycode == 'd' || keycode == 's'
		|| keycode == 'r' || keycode == 'f')
		game->key_states[keycode] = 0;
	if (keycode == RIGHT)
		game->key_states[0] = 0;
	if (keycode == LEFT)
		game->key_states[1] = 0;
	return (0);
}