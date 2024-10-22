/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:55:21 by llaakson          #+#    #+#             */
/*   Updated: 2024/09/11 19:33:45 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	close_window(t_game *game)
{
	free_images(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
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

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == 113 || keycode == 65307)
		close_window(game);
	if (keycode == 119)
		move_player(game, 1);
	if (keycode == 100)
		move_player(game, 2);
	if (keycode == 115)
		move_player(game, 3);
	if (keycode == 97)
		move_player(game, 4);
	return (0);
}

static void	check_arguments(int argc)
{
	if (argc != 2)
	{
		write(2, "Error\nWrong argument count\n", 27);
		exit (1);
	}
}

static void	init_game(t_game *game)
{
	game->window_w = 0;
	game->window_h = 0;
	game->move = 0;
	game->old_tile = '0';
	game->x = 0;
	game->y = 0;
	game->big = 0;
	game->window_w_big = 20;
	game->window_h_big = 20;
	game->mlx_win = NULL;
}

int	main(int argc, char	**argv)
{
	t_game	game;

	init_game(&game);
	check_arguments(argc);
	read_map(&game, argv[1]);
	validate_playable(&game);
	build_map(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
	{	
		write(2, "Error\nFailed to allocate mlx", 28);
		close_game_mini(&game);
	}
	open_window(&game);
	load_images(&game);
	fill_array_map(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 1L << 17, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
