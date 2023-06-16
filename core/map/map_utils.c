/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:59:23 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/16 05:31:45 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	height_map(t_game *game)
{
	int	map_height;

	map_height = 0;
	while (ft_strchr(game->map.map_size[map_height], '\n') != NULL)
		map_height++;
	return (map_height);
}

int	len_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

void	destroy_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map_size[i])
	{
		free(game->map.map_size[i]);
		i++;
	}
	free(game->map.map_size);
}

int	destroy_window(t_game *game)
{
	destroy_map(game);
	mlx_destroy_window(game->map.mlx, game->map.mlx_window);
	mlx_destroy_image(game->map.mlx, game->map.wall);
	mlx_destroy_image(game->map.mlx, game->map.empty);
	mlx_destroy_image(game->map.mlx, game->map.house);
	mlx_destroy_image(game->map.mlx, game->map.ped);
	mlx_destroy_image(game->map.mlx, game->map.ped_left);
	mlx_destroy_image(game->map.mlx, game->map.ped_back);
	mlx_destroy_image(game->map.mlx, game->map.ped_right);
	mlx_destroy_image(game->map.mlx, game->map.weapon);
	mlx_destroy_display(game->map.mlx);
	free(game->map.mlx);
	exit(0);
}
