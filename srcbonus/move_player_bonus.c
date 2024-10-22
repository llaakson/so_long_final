/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:12:10 by llaakson          #+#    #+#             */
/*   Updated: 2024/09/11 20:05:06 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	check_win(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->window_h)
	{
		while (j < game->window_w)
		{
			if (game->map_array[i][j] == 'C' || game->map_array[i][j] == 'E')
				return ;
			j++;
		}
		i++;
		j = 0;
	}
	close_window(game);
}

static int	wall(t_game *game, int code)
{
	if (code == 1 && game->map_array[game->y - 1][game->x] == '1')
		return (1);
	if (code == 2 && game->map_array[game->y][game->x + 1] == '1')
		return (1);
	if (code == 3 && game->map_array[game->y + 1][game->x] == '1')
		return (1);
	if (code == 4 && game->map_array[game->y][game->x - 1] == '1')
		return (1);
	game->move += 1;
	if (game->move == 2147483647)
		close_window(game);
	return (0);
}

static void	old_tile(t_game *game, int code)
{
	if (code == 1)
		game->old_tile = game->map_array[game->y - 1][game->x];
	if (code == 2)
		game->old_tile = game->map_array[game->y][game->x + 1];
	if (code == 3)
		game->old_tile = game->map_array[game->y + 1][game->x];
	if (code == 4)
		game->old_tile = game->map_array[game->y][game->x - 1];
	if (game->old_tile == 'C')
		game->old_tile = '0';
	if (game->old_tile == 'V')
		close_window(game);
}

void	move_player(t_game *game, int code)
{
	if (wall(game, code))
		return ;
	game->map_array[game->y][game->x] = game->old_tile;
	if (game->big == 0)
		put_image(game, game->map_array[game->y][game->x], game->y, game->x);
	if (game->big == 1)
		fill_array_big_map(game);
	old_tile(game, code);
	if (code == 1)
		game->y -= 1;
	if (code == 2)
		game->x += 1;
	if (code == 3)
		game->y += 1;
	if (code == 4)
		game->x -= 1;
	game->map_array[game->y][game->x] = 'P';
	if (game->big == 0)
		put_image(game, game->map_array[game->y][game->x], game->y, game->x);
	if (game->big == 1)
		fill_array_big_map(game);
	move_enemy(game);
	render_moves(game);
	check_win(game);
	check_lose(game);
}
