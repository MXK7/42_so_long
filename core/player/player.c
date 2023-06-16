/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:40:48 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/16 05:12:07 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	right(t_game *game)
{
	int	x;

	x = game->player.x + 32;
	if (check_move(game, x, game->player.y))
	{
		game->player.x = x;
		mlx_put_image_to_window(game->map.mlx, game->map.mlx_window,
			game->map.ped_right, game->player.x, game->player.y);
		mlx_put_image_to_window(game->map.mlx, game->map.mlx_window,
			game->map.empty, game->player.x - 32, game->player.y);
		update_move(game);
	}
}

void	left(t_game *game)
{
	int	x;

	x = game->player.x - 32;
	if (check_move(game, x, game->player.y))
	{
		game->player.x = x;
		mlx_put_image_to_window(game->map.mlx, game->map.mlx_window,
			game->map.ped_left, game->player.x, game->player.y);
		mlx_put_image_to_window(game->map.mlx, game->map.mlx_window,
			game->map.empty, game->player.x + 32, game->player.y);
		update_move(game);
	}
}

void	up(t_game *game)
{
	int	y;

	y = game->player.y - 32;
	if (check_move(game, game->player.x, y))
	{
		game->player.y = y;
		mlx_put_image_to_window(game->map.mlx, game->map.mlx_window,
			game->map.ped, game->player.x, game->player.y);
		mlx_put_image_to_window(game->map.mlx, game->map.mlx_window,
			game->map.empty, game->player.x, game->player.y + 32);
		update_move(game);
	}
}

void	down(t_game *game)
{
	int	y;

	y = game->player.y + 32;
	if (check_move(game, game->player.x, y))
	{
		game->player.y = y;
		mlx_put_image_to_window(game->map.mlx, game->map.mlx_window,
			game->map.ped_back, game->player.x, game->player.y);
		mlx_put_image_to_window(game->map.mlx, game->map.mlx_window,
			game->map.empty, game->player.x, game->player.y - 32);
		update_move(game);
	}
}
