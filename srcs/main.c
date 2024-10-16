/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:40 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/16 11:44:51 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_parse	*parse;
	t_game	*game;

	parse = malloc(sizeof(t_parse));
	if (!parse)
		return (printf("Error malloc parse\n"), ERROR);
	if (argc != 2)
		return (ERROR);
	if (parsing(argv[1], &parse) == ERROR)
		return (ERROR);
	game = malloc(sizeof(t_game));
	game->parsing = parse;
	printf("main fin\n");
	/* mlx_hook(game->fps_win, 2, 1L << 1, handle_keypress, game);
	mlx_hook(game->fps_win, 3, 1L << 0, handle_keyrelease, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->fps_win, 17, 0, close_window, game);
	mlx_loop(game->mlx); */
	free_all(game);
	return (SUCCESS);
}
