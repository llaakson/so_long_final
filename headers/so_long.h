/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:03:10 by llaakson          #+#    #+#             */
/*   Updated: 2024/09/11 22:06:17 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include "../libft/libft.h"

# ifndef IMG_SIZE
#  define IMG_SIZE 64
# endif

typedef struct s_game {
	void	*mlx;
	void	*mlx_win;
	char	*map;
	int		window_w;
	int		window_h;
	char	**map_array;
	char	**test_array;
	int		x;
	int		y;
	int		move;
	char	old_tile;
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit;
	int		big;
	int		window_w_big;
	int		window_h_big;
}	t_game;

int		main(int argc, char **argv);
void	read_map(t_game *game, char *map);
void	build_map(t_game *game);
void	get_player_position(t_game *game);
void	move_player(t_game *game, int code);
int		close_window(t_game *game);
void	load_images(t_game *game);
void	free_images(t_game *game);
void	update_terminal(t_game *game);
void	get_window_size(t_game *game);
void	validate_playable(t_game *game);
void	incorrect_map_exit(t_game *game, int i);
void	fill_array_map(t_game *game);
void	put_image(t_game *game, char c, int i, int j);
int		check_characters(t_game *game);
int		check_shape(t_game *game);
int		check_walls(t_game *game);
int		close_game_mini(t_game *game);
void	fill_array_big_map(t_game	*game);
void	open_window(t_game	*game);
void	follow_player_position(t_game *game);
void	check_if_big_map(t_game *game);

#endif
