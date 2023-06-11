/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 22:02:25 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/11 22:40:42 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// DISPLAY MAP WITH SPRITES
static void	display_map_elements(int x, int y, int image_x, int image_y)
{
	t_game	*game;

	while (x < game->map.map_width)
	{
		image_x = x * IMAGE_WIDTH;
		image_y = y * IMAGE_HEIGHT;
		if (game->map.map_size[y][x] == '1')
			put_image(game, "./assets/wall.xpm", image_x, image_y);
		else if (game->map.map_size[y][x] == 'E')
		{
			put_image(game, "./assets/house.xpm", image_x, image_y);
			game->map.house_x = image_x;
			game->map.house_y = image_y;
		}
		else if (game->map.map_size[y][x] == 'P' && game->init == 1)
		{
			game->init += 1;
			game->player.x = image_x;
			game->player.y = image_y;
		}
		x++;
	}
}

void	display_assets(t_game *game)
{
	int	image_x;
	int	image_y;
	int	x;
	int	y;

	y = 0;
	put_image(game, "./assets/bg3.xpm", 0, 1);
	while (y < game->map.map_height)
	{
		x = 0;
		display_map_elements(x, y, image_x, image_y);
		y++;
	}
}
