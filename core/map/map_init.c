/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:52:20 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/16 05:30:44 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// OPEN FOLDER MAP
void	init_map(t_game *game)
{
	char	*gnl;
	int		i;

	i = 0;
	gnl = get_next_line(game->map.fd);
	game->map.map_size = malloc(len_map(gnl) * sizeof(char *));
	game->map.map_width = len_map(gnl);
	while (gnl != NULL)
	{
		game->map.map_size[i] = gnl;
		gnl = get_next_line(game->map.fd);
		i++;
	}
	game->map.map_size[i] = '\0';
	game->map.map_height = i;
}
