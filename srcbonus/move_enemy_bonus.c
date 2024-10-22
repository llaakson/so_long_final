/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:07:06 by llaakson          #+#    #+#             */
/*   Updated: 2024/09/07 21:20:36 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	check_lose(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->window_h)
	{
		while (j < game->window_w)
		{
			if (game->map_array[i][j] == 'P')
				return ;
			j++;
		}
		i++;
		j = 0;
	}
	close_window(game);
}

static void	validate_enemy_move(t_game *game, int i, int j, int r)
{
	if (r == 0)
		game->map_array[i - 1][j] = 'V';
	else if (r == 1)
		game->map_array[i + 1][j] = 'V';
	else if (r == 2)
		game->map_array[i][j - 1] = 'V';
	else if (r == 3)
		game->map_array[i][j + 1] = 'V';
	game->map_array[i][j] = '0';
}

static int	update_enemy_move(t_game *game, int i, int j)
{
	int	r;

	r = rand() % 4;
	if (r == 0 && (game->map_array[i - 1][j] == '0'
		|| game->map_array[i - 1][j] == 'P'))
		validate_enemy_move(game, i, j, r);
	else if (r == 1 && (game->map_array[i + 1][j] == '0'
		|| game->map_array[i + 1][j] == 'P'))
		validate_enemy_move(game, i, j, r);
	else if (r == 2 && (game->map_array[i][j - 1] == '0'
		|| game->map_array[i][j - 1] == 'P'))
	{
		validate_enemy_move(game, i, j, r);
		return (j + 1);
	}
	else if (r == 3 && (game->map_array[i][j + 1] == '0'
		|| game->map_array[i][j + 1] == 'P'))
	{
		validate_enemy_move(game, i, j, r);
		return (j);
	}
	return (j);
}

int	move_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->window_h)
	{
		while (j < game->window_w)
		{
			if (game->map_array[i][j] == 'V')
			{
				j = update_enemy_move(game, i, j);
				i++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
