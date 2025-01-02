/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:40 by Matprod           #+#    #+#             */
/*   Updated: 2024/12/29 20:09:07 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	custom_usleep(unsigned int time)
{
	volatile unsigned int counter;

	counter = 0;
	while (counter < time)
		counter++;
	counter = 0;
	while (counter < time)
		counter++;
	counter = 0;
	while (counter < time)
		counter++;
	counter = 0;
	while (counter < time)
		counter++;
}

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

/* int handle_mouse_click(int button, t_game *game)
{
	if (button == 1)
		game->mouse_left = true;
	else if (button == 2)
		game->mouse_right = true;
	return (0);
}

int handle_mouse_release(int button, t_game *game)
{
	if (button == 1)
		game->mouse_left = false;
	else if (button == 2)
		game->mouse_right = false;

    return (0);
} */


//NE PAS OUBLIER WERROR
int	main(int argc, char **argv)
{
	t_parse	*parse;
	t_game	*game;

	if (argc != 2)
		return (error_msg(ERROR_NBR_ARG), ERROR);
	parse = NULL;
	game = NULL;
	if (get_singleton_list() == NULL)
		return (ERROR);
	if (parser(argv[1], &parse) == ERROR)	////LF (exept gnl)
		return (free_singleton_list(), ERROR);
	if (init_mlx(&game, parse) == ERROR)
		return (free_singleton_list(), ERROR);
	var_init(game);
	mlx_hook(game->fps_win, 2, 1L << 1, handle_keypress, game);
	mlx_hook(game->fps_win, 3, 1L << 0, handle_keyrelease, game);
	/* mlx_mouse_hook(game->fps_win, handle_mouse_click, game);
	mlx_hook(game->fps_win, 5, 1L << 3, handle_mouse_release, game); */
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->fps_win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	free_all(game);
	free_singleton_list();
	return (SUCCESS);
}

int	init_mlx(t_game **game, t_parse *parse)
{
	*game = ft_calloc(1, sizeof(t_game));
	if (!(*game))
		return (ERROR);
	if (add_singleton_data(*game, SINGLE_PTR) == ERROR)
		return (ERROR);
	(*game)->map = parse->map;
	(*game)->parsing = parse;
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		return (ERROR);

	(*game)->fps_win = mlx_new_window((*game)->mlx,
			RES_X, RES_Y, "cub3d");

	(*game)->fps_img.mlx_img = mlx_new_image((*game)->mlx, RES_X, RES_Y);
	(*game)->fps_img.addr = mlx_get_data_addr((*game)->fps_img.mlx_img,
			&(*game)->fps_img.bpp, &(*game)->fps_img.line_len,
			&(*game)->fps_img.endian);
	(*game)->fps_img.width = RES_X / 64;
	(*game)->fps_img.height = RES_Y / 64;
	return (SUCCESS);
}