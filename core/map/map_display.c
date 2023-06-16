/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 22:02:25 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/16 05:35:41 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// DISPLAY MAP WITH SPRITES
void	init_assets(t_game *game)
{
	int		size;

	size = 32;
	game->map.weapon = mlx_xpm_file_to_image(game->map.mlx,
			"./assets/weapon.xpm", &size, &size);
	game->map.ped = mlx_xpm_file_to_image(game->map.mlx,
			"./assets/ped.xpm", &size, &size);
	game->map.ped_left = mlx_xpm_file_to_image(game->map.mlx,
			"./assets/ped_left.xpm", &size, &size);
	game->map.ped_right = mlx_xpm_file_to_image(game->map.mlx,
			"./assets/ped_right.xpm", &size, &size);
	game->map.ped_back = mlx_xpm_file_to_image(game->map.mlx,
			"./assets/ped_back.xpm", &size, &size);
	game->map.wall = mlx_xpm_file_to_image(game->map.mlx,
			"./assets/wall.xpm", &size, &size);
	game->map.empty = mlx_xpm_file_to_image(game->map.mlx,
			"./assets/empty2.xpm", &size, &size);
	game->map.house = mlx_xpm_file_to_image(game->map.mlx,
			"./assets/house.xpm", &size, &size);
}

void	display_assets(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			if (game->map.map_size[y][x] == '0')
				display_empty(game, x, y);
			else if (game->map.map_size[y][x] == '1')
				display_wall(game, x, y);
			else if (game->map.map_size[y][x] == 'E')
				display_house(game, x, y);
			else if (game->map.map_size[y][x] == 'P')
				display_player(game, x, y);
			else if (game->map.map_size[y][x] == 'C')
				display_weapon(game, x, y);
			x++;
		}
		y++;
	}
}
