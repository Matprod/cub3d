/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:40 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/22 23:17:43 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**map_dup(char **map)
{
	char	**new_map;
	int		i;

	i = -1;
	new_map = malloc(sizeof(char *) * (map_height(map) + 1));
	if (!new_map)
		return (NULL);
	while (map[++i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_array(new_map);
			return (NULL);
		}
	}
	new_map[i] = NULL;
	return (new_map);
}

int	main(int argc, char **argv)
{
	t_parse	*parse;
	//t_game	*game;

	if (argc != 2)
		return (error_msg(ERROR_NBR_ARG), ERROR);
	if (get_singleton_list() == NULL)
		return (ERROR);
	//game = NULL;
	parse = malloc(sizeof(t_parse));
	if (!parse)
		return (error_msg(ERROR_MALLOC), ERROR);
	if (add_singleton_data(parse, SINGLE_PTR) == ERROR)
		return (free_singleton_list(), ERROR);
	if (parser(argv[1], &parse) == ERROR)
		return (free_singleton_list(), ERROR);
	return (free_singleton_list(), 0);



	//
	/* game = malloc(sizeof(t_game));
	memset(game, 0, sizeof(t_game));
 	game->map = map_dup(parse->map);
	game->parsing = parse;
	game->mlx = mlx_init();
	if (!game->mlx)
		free_all(game);
	game->fps_win = mlx_new_window(game->mlx,
			RES_X, RES_Y, "cub3d");
	game->fps_img.mlx_img = mlx_new_image(game->mlx, RES_X, RES_Y);
	game->fps_img.addr = mlx_get_data_addr(game->fps_img.mlx_img,
			&game->fps_img.bpp, &game->fps_img.line_len,
			&game->fps_img.endian);
	game->fps_img.width = RES_X / 64;
	game->fps_img.height = RES_Y / 64;

	var_init(game);
	usleep(1000);
	mlx_hook(game->fps_win, 2, 1L << 1, handle_keypress, game);
	mlx_hook(game->fps_win, 3, 1L << 0, handle_keyrelease, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->fps_win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	free_all(game); */
	return (SUCCESS);
}
