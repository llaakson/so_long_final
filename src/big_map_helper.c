/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:53:48 by llaakson          #+#    #+#             */
/*   Updated: 2024/09/11 18:41:32 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	open_window(t_game *game)
{
	if (game->big == 0)
	{
		game->mlx_win = mlx_new_window(game->mlx, game->window_w
				* IMG_SIZE, game->window_h * IMG_SIZE, "so_long");
	}
	if (game->big == 1)
	{
		game->mlx_win = mlx_new_window(game->mlx, game->window_w_big
				* IMG_SIZE, game->window_h_big * IMG_SIZE, "so_long");
	}
	if (!game->mlx_win)
	{
		mlx_destroy_display(game->mlx);
		write(2, "Error\nCreating window failed\n", 29);
		close_game_mini(game);
	}
}

static int	get_x(t_game	*game)
{
	if (game->x < 10)
		return (0);
	else if (game->x >= 10 && game->x < (game->window_w - 10))
		return (game->x - 10);
	else
		return (game->window_w - 20);
}

static int	get_y(t_game	*game)
{
	if (game->y < 10)
		return (0);
	else if (game->y >= 10 && game->y < (game->window_h - 10))
		return (game->y -10);
	else
		return (game->window_h - 20);
}

void	fill_array_big_map(t_game	*game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	follow_player_position(game);
	x = get_x(game);
	y = get_y(game);
	while (i < game->window_h_big)
	{
		while (j < game->window_w_big)
		{
			put_image(game, game->map_array[y][x], i, j);
			x++;
			j++;
		}
		j = 0;
		x = get_x(game);
		y++;
		i++;
	}
}

void	check_if_big_map(t_game *game)
{
	game->big = 1;
	if (game->window_w < 20)
		game->window_w_big = game->window_w;
	if (game->window_h < 20)
		game->window_h_big = game->window_h;
}
