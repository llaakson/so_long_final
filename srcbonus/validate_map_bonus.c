/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:59:10 by llaakson          #+#    #+#             */
/*   Updated: 2024/08/12 06:07:44 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	check_characters(t_game *game)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'P' || game->map[i] == 'E')
			c += 1;
		i++;
	}
	return (c);
}

int	check_shape(t_game *game)
{
	char	*map;
	int		i;
	int		j;

	j = 0;
	map = game->map;
	i = 0;
	while (map[i] != '\n')
		i++;
	while (*map)
	{
		map++;
		j++;
		if (((*map == '\n') && (i != j)))
			return (1);
		if (*map == '\n')
			j = -1;
	}
	return (0);
}

int	check_walls(t_game *game)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	h = 0;
	get_window_size(game);
	while (game->map[i] != '\0')
	{
		w = 0;
		while (game->map[i] != '\n')
		{
			if ((h == 0 && game->map[i] != '1')
				|| (h == game->window_h - 1 && game->map[i] != '1'))
				return (1);
			if ((w == 0 || w == game->window_w - 1) && game->map[i] != '1')
				return (1);
			i++;
			w++;
		}
		i++;
		h++;
	}
	return (0);
}
