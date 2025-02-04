/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:08:10 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/04 16:50:30 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* t_img	*get_wall_texture(t_game *game, t_collision collision)
{
	static int	i = 0;

	if (collision.orientation == 'N')
	{
		i++;
		if (i < 1000)
			return (&game->texture.north);
		else if (i >= 1000 && i <= 2000)
			return (&game->texture.north_two);
		else if (i >= 2000 && i <= 3000)
			return (&game->texture.north_three);
		else if (i > 3000)
		{
			i = 0;
			return (&game->texture.north);
		}
	}
	else if (collision.orientation == 'S')
		return (&game->texture.south);
	else if (collision.orientation == 'E')
		return (&game->texture.east);
	else if (collision.orientation == 'W')
		return (&game->texture.west);
	return (NULL);
} */

t_img	*get_north_texture(t_game *game)
{
	static long	start = 0;
	long		current_time;

	if (start == 0)
		start = get_time();
	current_time = get_time();
	if (current_time < start + 600)
		return (&game->texture.north);
	else if (current_time < start + 1200)
		return (&game->texture.north_two);
	else if (current_time < start + 1800)
		return (&game->texture.north_three);
	start = get_time();
	return (&game->texture.north);
}

t_img	*get_east_texture(t_game *game)
{
	static long	start = 0;
	long		current_time;
	int			morty_index;

	if (start == 0)
		start = get_time();
	current_time = get_time();
	morty_index = ((current_time - start) / 125) % MORTY_FRAMES;
	if (morty_index >= 0 && morty_index < MORTY_FRAMES)
		return (&game->texture.morty[morty_index]);
	return (NULL);
}

t_img	*get_wall_texture(t_game *game, t_collision collision)
{
	if (collision.orientation == 'N')
		return (get_north_texture(game));
	else if (collision.orientation == 'S')
		return (&game->texture.south);
	else if (collision.orientation == 'E')
		return (get_east_texture(game));
	else if (collision.orientation == 'W')
		return (&game->texture.west);
	return (NULL);
}

/* t_img	*get_wall_texture(t_game *game, t_collision collision)
{
	static int	i = 0;

	if (collision.orientation == 'N')
	{
		i++;
		if (i < 20000000)
			return (&game->texture.north);
		else if (i >= 20000000 && i <= 40000000)
			return (&game->texture.north_two);
		else if (i >= 40000000 && i <= 60000000)
			return (&game->texture.north_three);
		else if (i > 60000000)
		{
			i = 0;
			return (&game->texture.north);
		}
	}
	else if (collision.orientation == 'S')
		return (&game->texture.south);
	else if (collision.orientation == 'E')
		return (&game->texture.east);
	else if (collision.orientation == 'W')
		return (&game->texture.west);
	return (NULL);
} */