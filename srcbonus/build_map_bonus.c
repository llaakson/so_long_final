/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:53:48 by llaakson          #+#    #+#             */
/*   Updated: 2024/09/11 18:57:39 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	build_map(t_game *game)
{
	game->map_array = ft_split(game->map, '\n');
	if (!game->map_array)
	{
		free(game->map);
		write(2, "Error\nFailed creating the map\n", 31);
		exit(1);
	}
}

void	get_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->window_h)
	{
		while (j < game->window_w)
		{
			if (game->test_array[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	follow_player_position(t_game *game)
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
			{
				game->x = j;
				game->y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	get_window_size(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[game->window_w] != '\n')
		game->window_w++;
	while (game->map[i] != '\0')
	{
		if (game->map[i] == '\n')
			game->window_h++;
		i++;
	}
}
