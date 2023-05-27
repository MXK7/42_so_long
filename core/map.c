/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:52:20 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/28 00:04:57 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

#define true 1
#define false 0
#define bool int

// OPEN FOLDER MAP
void	init_map(t_game *game)
{
	int		i;
	bool	x;

	if (!game->map.fd)
		error(ERROR_INIT_MAP);
	i = 0;
	x = false;
	while (x >= true)
	{
		game->map.map_size[i] = get_next_line(game->map.fd);
		printf("%s", game->map.map_size[i]);
		if (game->map.map_size[i] == NULL)
			x = false;
		i++;
	}
}

// CHECK BORDER AND WALL
int	check_shape(t_game *game)
{
	int	i;

	i = 1;
	while (game->map.map_size[i])
	{
		if (fr_strlen(game->map.map_size[i]) != ft_strlen(game->map.map_size[i
				- 1]))
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(t_game *game)
{
	int top, bottom, right, left;

	top, bottom, left, right = 0, 0, 0, 0;
	while (game->map.map_size[top] != '\0' && game->map.map_size[0][top] != 1)
		top++;
	while (game->map.map_size[bottom] != '\0' && game->map.map_size[0][bottom] != 1)
		bottom++;
	while (left <= bottom && game->map.map_size[left][0] != 1)
		left++;
	while (right <= bottom && game->map.map_size[right][0] != 1)
		right++;
	return (1);
}