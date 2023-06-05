/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:59:23 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/05 03:56:25 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_height(t_game *game)
{
	int	map_height;

	map_height = 0;
	while (ft_strchr(game->map.map_size[map_height], '\n') != NULL)
		map_height++;
	return (map_height);
}

void	map_destroy(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map_size[i] != NULL)
	{
		free(game->map.map_size[i]);
		i++;
	}
	free(game->map.map_size);
}

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->map.mlx, game->map.mlx_window);
	map_destroy(game);
	exit(0);
}

void	*put_image(t_game *game, char *relative_path, int x, int y)
{
	game->map.xpm = mlx_xpm_file_to_image(game->map.mlx, relative_path,
			&game->map.x, &game->map.y);
	mlx_put_image_to_window(game->map.mlx, game->map.mlx_window, game->map.xpm,
			x, y);
	return (game->map.xpm);
}