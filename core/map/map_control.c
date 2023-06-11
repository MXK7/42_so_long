/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:04:30 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/11 22:49:38 by mpoussie         ###   ########.fr       */
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
