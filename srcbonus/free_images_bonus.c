/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:58:49 by llaakson          #+#    #+#             */
/*   Updated: 2024/09/08 22:40:24 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	image_load_fail(t_game *game)
{
	write(2, "Error\nImage loading failed\n", 27);
	close_window(game);
}

static void	free_enemy(t_game *game)
{
	if (game->enemy)
		mlx_destroy_image(game->mlx, game->enemy);
	if (game->enemy2)
		mlx_destroy_image(game->mlx, game->enemy2);
	if (game->enemy3)
		mlx_destroy_image(game->mlx, game->enemy3);
	if (game->enemy4)
		mlx_destroy_image(game->mlx, game->enemy4);
	if (game->enemy5)
		mlx_destroy_image(game->mlx, game->enemy5);
}

void	free_images(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->player1)
		mlx_destroy_image(game->mlx, game->player1);
	if (game->player2)
		mlx_destroy_image(game->mlx, game->player2);
	if (game->player3)
		mlx_destroy_image(game->mlx, game->player3);
	if (game->player4)
		mlx_destroy_image(game->mlx, game->player4);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	free_enemy(game);
}
