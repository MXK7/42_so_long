/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:04:30 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/05 05:09:16 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// CHECK BORDER AND WALL
int	check_shape(t_game *game)
{
	int	i;
	int	map_width;

	i = 1;
	map_width = ft_strlen(game->map.map_size[0]);
	if (!game->map.map_size)
		error(ERROR_CHECK_WALL);
	while (game->map.map_size[i] != NULL)
	{
		printf("CHECK_SHAPE:\n%s", game->map.map_size[i]);
		if (ft_strlen(game->map.map_size[i]) != map_width)
			return (0);
		i++;
	}
	return (1);
}

// int	check_wall(t_game *game)
// {
// 	int	top;
// 	int	bottom;
// 	int	right;
// 	int	left;
// 	int	player_x;
// 	int	player_y;
// 	int	map_width;
// 	int	map_height;

// 	top = 0;
// 	bottom = 0;
// 	right = 0;
// 	left = 0;
// 	player_x = game->player.x;
// 	player_y = game->player.y;
// 	map_width = game->map.map_width;
// 	map_height = game->map.map_height;
// 	if (!game->map.map_size)
// 	{
// 		error(ERROR_CHECK_WALL);
// 	}
// 	while (game->map.map_size[top] != NULL)
// 	{
// 		if (game->map.map_size[top][map_width - 1] != '1')
// 			return (0);
// 		top++;
// 	}
// 	while (game->map.map_size[bottom] != NULL)
// 	{
// 		if (game->map.map_size[bottom][map_width - 1] != '1')
// 			return (0);
// 		bottom++;
// 	}
// 	while (left < bottom)
// 	{
// 		if (game->map.map_size[left][0] != '1')
// 			return (0);
// 		left++;
// 	}
// 	while (right < bottom)
// 	{
// 		if (game->map.map_size[right][map_width - 1] != '1')
// 			return (0);
// 		right++;
// 	}
// 	// Vérification des murs adjacents au joueur
// 	if (player_y > 0 && game->map.map_size[player_y - 1][player_x] == '1')
// 		return (0);
// 	if (player_y < map_height - 1 && game->map.map_size[player_y
// 		+ 1][player_x] == '1')
// 		return (0);
// 	if (player_x > 0 && game->map.map_size[player_y][player_x - 1] == '1')
// 		return (0);
// 	if (player_x < map_width - 1 && game->map.map_size[player_y][player_x
// 		+ 1] == '1') // Mur à droite
// 		return (0);
// 	return (1);
// }


int check_wall(t_game *game)
{
    int player_x = game->player.x;
    int player_y = game->player.y;

    // Vérification des murs adjacents au joueur
    if (player_y > 0 && game->map.map_size[player_y - 1][player_x] == '1')
        return 0;
    if (player_y < game->map.map_height - 1 && game->map.map_size[player_y + 1][player_x] == '1')
        return 0;
    if (player_x > 0 && game->map.map_size[player_y][player_x - 1] == '1')
        return 0;
    if (player_x < game->map.map_width - 1 && game->map.map_size[player_y][player_x + 1] == '1')
        return 0;
    return 1;
}
