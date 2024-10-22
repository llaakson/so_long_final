/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:19:43 by llaakson          #+#    #+#             */
/*   Updated: 2024/09/12 16:36:14 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	print_error(int i)
{
	if (i == -1)
		write(2, "Error\nWrong symbol in map\n", 26);
	if (i == -2)
		write(2, "Error\nToo few collectibles\n", 27);
	if (i == -3)
		write(2, "Error\nMap can only have one exit and one player\n", 49);
	if (i == -4)
		write(2, "Error\nMap not a rectangle\n", 26);
	if (i == -5)
		write(2, "Error\nMap has no walls\n", 23);
}

void	incorrect_map_exit(t_game *game, int i)
{
	print_error(i);
	free(game->map);
	exit (1);
}

int	close_game_mini(t_game *game)
{
	free(game->mlx);
	while (game->window_h >= 0)
	{
		free(game->map_array[game->window_h]);
		game->window_h--;
	}
	free(game->map_array);
	free(game->map);
	exit(1);
}
