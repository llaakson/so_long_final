/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 04:09:38 by llaakson          #+#    #+#             */
/*   Updated: 2024/09/11 19:56:04 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	render_moves(t_game *game)
{	
	int		x;
	int		y;
	char	*moves;
	char	*str;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 192)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	str = "MOVES : ";
	moves = ft_itoa(game->move);
	str = ft_strjoin(str, moves);
	mlx_string_put(game->mlx, game->mlx_win, 5, 32, 0x000000, str);
	free(str);
	free(moves);
}

int	fill_array_map_no_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->big == 1)
	{
		fill_array_big_map(game);
		return (0);
	}
	while (i < game->window_h)
	{
		while (j < game->window_w)
		{
			if (game->map_array[i][j] != '1')
				put_image(game, game->map_array[i][j], i, j);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	fill_array_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->big == 1)
	{
		fill_array_big_map(game);
		return (0);
	}
	while (i < game->window_h)
	{
		while (j < game->window_w)
		{
			put_image(game, game->map_array[i][j], i, j);
			j++;
		}
		j = 0;
		i++;
	}
	render_moves(game);
	return (0);
}
