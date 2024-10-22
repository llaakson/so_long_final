/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_playable_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:31:05 by llaakson          #+#    #+#             */
/*   Updated: 2024/09/08 22:40:10 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static int	check_completion(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->window_h)
	{
		while (j < game->window_w)
		{
			if (game->test_array[i][j] == 'C' || game->test_array[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

static void	play_the_map(t_game *game, int x, int y)
{
	if (game->test_array[y][x] == '1')
		return ;
	game->test_array[y][x] = '1';
	play_the_map(game, (x + 1), y);
	play_the_map(game, (x - 1), y);
	play_the_map(game, x, (y + 1));
	play_the_map(game, x, (y - 1));
}

static void	free_test_array(t_game *game)
{
	int	i;

	i = game->window_h;
	while (i >= 0)
	{
		free(game->test_array[i]);
		i--;
	}
	free(game->test_array);
}

void	validate_playable(t_game *game)
{
	game->test_array = ft_split(game->map, '\n');
	if (!game->test_array)
	{
		free(game->map);
		write(2, "Error\nFailed creating the test map\n", 36);
		exit (1);
	}
	get_player_position(game);
	play_the_map(game, game->x, game->y);
	if (check_completion(game))
	{	
		write(2, "Error\nMap is not playable\n", 26);
		free_test_array(game);
		free(game->map);
		exit(1);
	}
	free_test_array(game);
}
