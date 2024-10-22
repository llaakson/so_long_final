/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 06:04:05 by llaakson          #+#    #+#             */
/*   Updated: 2024/09/11 22:06:33 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <errno.h>
# include "../libft/libft.h"

# ifndef IMG_SIZE
#  define IMG_SIZE 64
# endif

typedef struct s_game {
	void				*mlx;
	void				*mlx_win;
	char				*map;
	int					window_w;
	int					window_h;
	char				**map_array;
	char				**test_array;
	int					x;
	int					y;
	int					move;
	char				old_tile;
	void				*wall;
	void				*floor;
	void				*player;
	void				*player1;
	void				*player2;
	void				*player3;
	void				*player4;
	void				*collect;
	void				*exit;
	void				*enemy;
	void				*enemy2;
	void				*enemy3;
	void				*enemy4;
	void				*enemy5;
	struct timespec		time;
	int					big;
	int					window_w_big;
	int					window_h_big;
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
int		fill_array_map(t_game *game);
void	put_image(t_game *game, char c, int i, int j);
int		move_enemy(t_game *game);
void	check_lose(t_game *game);
int		fill_array_map_no_walls(t_game *game);
void	render_moves(t_game *games);
int		check_characters(t_game *game);
int		check_shape(t_game *game);
int		check_walls(t_game *game);
int		close_game_mini(t_game *game);
void	image_load_fail(t_game *game);
void	fill_array_big_map(t_game	*game);
void	open_window(t_game	*game);
void	follow_player_position(t_game *game);
void	check_if_big_map(t_game *game);

#endif
