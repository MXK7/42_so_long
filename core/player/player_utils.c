/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:40:46 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/16 05:12:24 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_move(t_game *game, int new_x, int new_y)
{
	new_x = new_x / 32;
	new_y = new_y / 32;
	if (new_x < 0 || new_y < 0 || new_x > game->map.map_width
		|| new_y > game->map.map_height)
		return (0);
	if (game->map.map_size[new_y][new_x] == '1')
		return (0);
	if (game->map.map_size[new_y][new_x] == 'C')
	{
		game->map.weaponItems++;
		game->map.map_size[new_y][new_x] = '0';
	}
	if (game->map.map_size[new_y][new_x] == 'E'
		&& game->map.weaponItems == game->map.info.weaponItems)
		destroy_window(game);
	else if (game->map.map_size[new_y][new_x] == 'E'
			&& game->map.weaponItems != game->map.info.weaponItems)
		return (0);
	return (1);
}

void	update_move(t_game *game)
{
	game->player.mouv++;
	ft_printf("Number of steps : %d\n", game->player.mouv);
}
