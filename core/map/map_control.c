/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:04:30 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/16 05:15:58 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// CHECK BORDER AND WALL
int	check_shape(t_game *game)
{
	int	i;
	int	len;
	int	len2;

	i = 1;
	len = ft_strlen(game->map.map_size[0]);
	len2 = ft_strlen(game->map.map_size[i]);
	if (!game->map.map_size)
		error(ERROR_CHECK_WALL);
	while (game->map.map_size[i] != NULL)
	{
		if (len2 != len)
			return (0);
		i++;
	}
	return (1);
}

void	check_map(t_game *game)
{
	if (game->map.info.empty == 0 || game->map.info.wall == 0
		|| game->map.info.house == 0 || game->map.info.ped == 0)
	{
		error(ERROR_MAP);
		free(game->map.map_size);
		destroy_window(game);
		exit(0);
	}
}
