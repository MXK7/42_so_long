/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 05:25:06 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/16 05:26:01 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	display_empty(t_game *game, int x, int y)
{
	int	image_x;
	int	image_y;

	image_x = x * IMAGE_WIDTH;
	image_y = y * IMAGE_HEIGHT;
	mlx_put_image_to_window(game->map.mlx, game->map.mlx_window,
		game->map.empty, image_x, image_y);
	game->map.info.empty++;
}

void	display_wall(t_game *game, int x, int y)
{
	int	image_x;
	int	image_y;

	image_x = x * IMAGE_WIDTH;
	image_y = y * IMAGE_HEIGHT;
	mlx_put_image_to_window(game->map.mlx, game->map.mlx_window, game->map.wall,
		image_x, image_y);
	game->map.info.wall++;
}

void	display_house(t_game *game, int x, int y)
{
	int	image_x;
	int	image_y;

	image_x = x * IMAGE_WIDTH;
	image_y = y * IMAGE_HEIGHT;
	game->map.info.house++;
	mlx_put_image_to_window(game->map.mlx, game->map.mlx_window,
		game->map.house, image_x, image_y);
	game->map.house_x = image_x;
	game->map.house_y = image_y;
}

void	display_player(t_game *game, int x, int y)
{
	int	image_x;
	int	image_y;

	image_x = x * IMAGE_WIDTH;
	image_y = y * IMAGE_HEIGHT;
	game->init++;
	game->player.x = image_x;
	game->player.y = image_y;
	mlx_put_image_to_window(game->map.mlx, game->map.mlx_window, game->map.ped,
		image_x, image_y);
	game->map.info.ped++;
}

void	display_weapon(t_game *game, int x, int y)
{
	int	image_x;
	int	image_y;

	image_x = x * IMAGE_WIDTH;
	image_y = y * IMAGE_HEIGHT;
	game->map.info.weaponItems++;
	mlx_put_image_to_window(game->map.mlx, game->map.mlx_window,
		game->map.weapon, image_x, image_y);
	game->map.info.weapon++;
}
