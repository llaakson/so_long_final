/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:08:58 by llaakson          #+#    #+#             */
/*   Updated: 2024/09/12 17:19:46 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	check_ber(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (map[i - 4] != '.' || map[i - 3] != 'b'
		|| map[i - 2] != 'e' || map[i - 1] != 'r')
	{
		write(2, "Error\nMap is not a .ber file type\n", 35);
		exit (1);
	}
}

static void	validate_map(t_game *game)
{
	char	*map;
	int		character;

	character = 0;
	map = game->map;
	while (*map)
	{
		if (*map != 'P' && *map != 'C' && *map != 'E'
			&& *map != '1' && *map != '0' && *map != '\n' && *map != 'V')
			incorrect_map_exit(game, -1);
		if (*map == 'C')
			character += 1;
		map++;
	}
	if (character < 1)
		incorrect_map_exit(game, -2);
	character = check_characters(game);
	if (character != 2)
		incorrect_map_exit(game, -3);
	if (check_shape(game))
		incorrect_map_exit(game, -4);
	if (check_walls(game))
		incorrect_map_exit(game, -5);
	if (game->window_w >= 40 || game->window_h >= 26)
		check_if_big_map(game);
}

void	read_map_gnl(t_game *game, int fd)
{
	char	*map_temp;

	while (1)
	{
		map_temp = get_next_line(fd);
		if (errno != 0)
		{
			close(fd);
			free(game->map);
			write(2, "Error\nReading map failed\n", 25);
			exit(1);
		}
		if (map_temp == NULL)
			break ;
		game->map = ft_strjoin_free(game->map, map_temp);
		if (!game->map)
		{
			close(fd);
			free(map_temp);
			write(2, "Error\nReading map failedi\n", 25);
			exit(1);
		}
		free(map_temp);
	}
	close(fd);
}

void	read_map(t_game *game, char *map)
{
	int		fd;

	check_ber(map);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFile not found\n", 21);
		exit (1);
	}
	game->map = malloc(1);
	if (!game->map)
	{
		close(fd);
		write(2, "Error\nFailed to allocate memory for map", 39);
		exit (1);
	}
	game->map[0] = '\0';
	read_map_gnl(game, fd);
	validate_map(game);
}
