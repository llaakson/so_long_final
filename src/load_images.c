/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:16:25 by llaakson          #+#    #+#             */
/*   Updated: 2024/09/11 18:48:41 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	put_image(t_game *game, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->wall, j * IMG_SIZE, i * IMG_SIZE);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->floor, j * IMG_SIZE, i * IMG_SIZE);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player, j * IMG_SIZE, i * IMG_SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->collect, j * IMG_SIZE, i * IMG_SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->exit, j * IMG_SIZE, i * IMG_SIZE);
}

void	fill_array_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->big == 1)
	{
		fill_array_big_map(game);
		return ;
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
}

static void	image_load_fail(t_game *game)
{
	write(2, "Error\nImage loading failed\n", 27);
	close_window(game);
}

static void	check_images(t_game *game)
{
	if (!game->wall)
		image_load_fail(game);
	if (!game->floor)
		image_load_fail(game);
	if (!game->player)
		image_load_fail(game);
	if (!game->collect)
		image_load_fail(game);
	if (!game->exit)
		image_load_fail(game);
}

void	load_images(t_game *game)
{
	int	s;

	s = IMG_SIZE;
	game->wall = mlx_xpm_file_to_image(game->mlx, "./assets/1.xpm", &s, &s);
	game->floor = mlx_xpm_file_to_image(game->mlx, "./assets/0.xpm", &s, &s);
	game->player = mlx_xpm_file_to_image(game->mlx, "./assets/P.xpm", &s, &s);
	game->collect = mlx_xpm_file_to_image(game->mlx, "./assets/C.xpm", &s, &s);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./assets/E.xpm", &s, &s);
	check_images(game);
}
