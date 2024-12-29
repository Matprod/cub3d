/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:35:14 by Matprod           #+#    #+#             */
/*   Updated: 2024/12/29 19:50:39 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_walkable(t_game *game, float x, float y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)x;
	grid_y = (int)y;
	if (game->map[grid_y][grid_x] == '1')
		return (0);
	return (1);
}

void player_wall_collides(t_game *game, t_vector speed)
{
	t_vector v_offset;
	t_vector vi_pos;
	t_vector vi_pos_add_offset;

	v_offset.x = 0;
	v_offset.y = 0;
	if (speed.x > 0)
		v_offset.x = 25;
	else
		v_offset.x = -25;
	if (speed.y > 0)
		v_offset.y = 25;
	else
		v_offset.y = -25;
	vi_pos = pixel_to_tile(vec_sum(game->player.pos, game->player.speed));
	vi_pos_add_offset = pixel_to_tile(vec_sum(game->player.pos, v_offset));
	if (!is_walkable(game, vi_pos_add_offset.x, vi_pos.y))
		game->player.speed.x = 0;
	if (!is_walkable(game, vi_pos.x, vi_pos_add_offset.y))
		game->player.speed.y = 0;
}



void	edit_player_pos(t_game *game)
{
	t_vector	right;
	t_vector	left;

	right = vec_rotate(game->player.direction, 90);
	left = vec_rotate(game->player.direction, 270);
	if (game->key_states['w'])
		game->player.speed = vec_scalar_mult(game->player.direction, 1);
	else if (game->key_states['s'])
		game->player.speed = vec_scalar_mult(game->player.direction, -1);
	if (game->key_states['a'])
		game->player.speed = vec_sum(game->player.speed, left);
	else if (game->key_states['d'])
		game->player.speed = vec_sum(game->player.speed, right);
	if (game->key_states['a'] || game->key_states['d'])
		game->player.speed = vec_normalize(game->player.speed);
	if (game->key_states[2] && game->key_states['w'])
		game->player.speed = vec_scalar_mult(game->player.speed, 12);
	else
		game->player.speed = vec_scalar_mult(game->player.speed, 6);
	player_wall_collides(game, game->player.speed);
	game->player.pos = vec_sum(game->player.pos, game->player.speed);
	game->player.speed.x = 0;
	game->player.speed.y = 0;
}

void	edit_player_rotate(t_game *game)
{
	if (game->key_states[0])
		vec_rotate_edit(&(game->player.direction), -4);
	if (game->key_states[1])
		vec_rotate_edit(&(game->player.direction), 4);
	if (game->key_states['r'])
		game->player.direction_adjust += 0.1;
	if (game->key_states['f'])
		game->player.direction_adjust -= 0.1;
}

void fps(void)
{
	static int counter = 0;
    static time_t last_call_time = 0; 
	time_t		current_time;

	current_time = time(NULL);	
	if (last_call_time == 0)
	    last_call_time = current_time;	
	counter++;
	if (current_time > last_call_time)
	{
		printf("FPS %d\n", counter);
		counter = 0;
		last_call_time = current_time;
	}
}

int	game_loop(void *g)
{
	t_game	*game;

	game = (t_game *)g;
	edit_player_pos(game);
	edit_player_rotate(game);
	render(game);
	fps();// A ENLEVER A LA FIN
	return (0);
}