/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:40:46 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/05 04:07:21 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// int	move_check(t_game *game, int i, int j)
// {
// 	if (game->map.map_size[i][j] == '1')
// 		return (1);
// 	else if (game->map.map_size[i][j] == 'C')
// 	{
// 		game->player.corner++;
// 		game->map.map_size[i][j] = '0';
// 	}
// 	else if (game->map.map_size[i][j] == 'E')
// 	{
// 		if (game->player.corner != game->player.corner_check)
// 		{
// 			// error("Do you think you killed them all");
// 			return (1);
// 		}
// 		return (0);
// 	}
// 	return (0);
// }

int	move_check(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.map_size[0][new_x] || new_y < 0 || new_y >= game->map.map_size[new_y][0])
		return (0);
	if (game->map.map_size[new_y][new_x] == '1')
		return (0);
	return (1);
}