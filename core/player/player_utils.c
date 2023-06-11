/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:40:46 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/11 22:54:05 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_move(t_game *game, int new_x, int new_y)
{
	new_x = new_x / 32;
	new_y = new_y / 32;
	printf("\n%c\n", game->map.map_size[new_y][new_x]);
	if (new_x < 0 || new_y < 0 || new_x > game->map.map_width
		|| new_y > game->map.map_height)
		return (0);
	if (game->map.map_size[new_y][new_x] == '1')
		return (0);
	if (game->map.map_size[new_y][new_x] == 'E')
	{
		destroy_window(game);
	}
	return (1);
}
