/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:16:25 by llaakson          #+#    #+#             */
/*   Updated: 2024/08/27 13:26:12 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	player_animation(t_game *game, int i, int j, int loop_time)
{
	if (loop_time % 1000 < 200)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player, j * IMG_SIZE, i * IMG_SIZE);
	else if (loop_time % 1000 < 400)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player1, j * IMG_SIZE, i * IMG_SIZE);
	else if (loop_time % 1000 < 600)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player2, j * IMG_SIZE, i * IMG_SIZE);
	else if (loop_time % 1000 < 800)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player3, j * IMG_SIZE, i * IMG_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player4, j * IMG_SIZE, i * IMG_SIZE);
}

static void	enemy_animation(t_game *game, int i, int j, int loop_time)
{
	if (loop_time % 1000 < 200)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->enemy, j * IMG_SIZE, i * IMG_SIZE);
	else if (loop_time % 1000 < 400)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->enemy2, j * IMG_SIZE, i * IMG_SIZE);
	else if (loop_time % 1000 < 600)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->enemy3, j * IMG_SIZE, i * IMG_SIZE);
	else if (loop_time % 1000 < 800)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->enemy4, j * IMG_SIZE, i * IMG_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->enemy5, j * IMG_SIZE, i * IMG_SIZE);
}

void	put_image(t_game *game, char c, int i, int j)
{
	int				loop_time;

	clock_gettime(CLOCK_MONOTONIC, &game->time);
	loop_time = game->time.tv_sec * 1000 + game->time.tv_nsec / 1000000;
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->wall, j * IMG_SIZE, i * IMG_SIZE);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->floor, j * IMG_SIZE, i * IMG_SIZE);
	else if (c == 'P')
		player_animation(game, i, j, loop_time);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->collect, j * IMG_SIZE, i * IMG_SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->exit, j * IMG_SIZE, i * IMG_SIZE);
	else if (c == 'V')
		enemy_animation(game, i, j, loop_time);
}

static void	check_images(t_game *game)
{
	if (!game->wall)
		image_load_fail(game);
	if (!game->floor)
		image_load_fail(game);
	if (!game->exit)
		image_load_fail(game);
	if (!game->collect)
		image_load_fail(game);
	if (!game->player || !game->player1 || !game->player2
		|| !game->player3 || !game->player4)
		image_load_fail(game);
	if (!game->enemy || !game->enemy2 || !game->enemy3
		|| !game->enemy4 || !game->enemy5)
		image_load_fail(game);
}	

void	load_images(t_game *game)
{
	int	s;

	s = IMG_SIZE;
	game->wall = mlx_xpm_file_to_image(game->mlx, "./assets/1.xpm", &s, &s);
	game->floor = mlx_xpm_file_to_image(game->mlx, "./assets/0.xpm", &s, &s);
	game->player = mlx_xpm_file_to_image(game->mlx, "./assets/P.xpm", &s, &s);
	game->player1 = mlx_xpm_file_to_image(game->mlx, "./assets/P1.xpm", &s, &s);
	game->player2 = mlx_xpm_file_to_image(game->mlx, "./assets/P2.xpm", &s, &s);
	game->player3 = mlx_xpm_file_to_image(game->mlx, "./assets/P3.xpm", &s, &s);
	game->player4 = mlx_xpm_file_to_image(game->mlx, "./assets/P4.xpm", &s, &s);
	game->collect = mlx_xpm_file_to_image(game->mlx, "./assets/C.xpm", &s, &s);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./assets/E.xpm", &s, &s);
	game->enemy = mlx_xpm_file_to_image(game->mlx, "./assets/V.xpm", &s, &s);
	game->enemy2 = mlx_xpm_file_to_image(game->mlx, "./assets/V2.xpm", &s, &s);
	game->enemy3 = mlx_xpm_file_to_image(game->mlx, "./assets/V3.xpm", &s, &s);
	game->enemy4 = mlx_xpm_file_to_image(game->mlx, "./assets/V4.xpm", &s, &s);
	game->enemy5 = mlx_xpm_file_to_image(game->mlx, "./assets/V5.xpm", &s, &s);
	check_images(game);
}
