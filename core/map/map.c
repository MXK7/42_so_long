/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:52:20 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/03 23:02:07 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// OPEN FOLDER MAP
static void	allocate_memory(t_game *game, int y)
{
	bool	x;
	int		i;
	char	*line;

	i = 0;
	x = true;
	while (x != false)
	{
		if (line == NULL)
			x = false;
		line = get_next_line(game->map.fd);
		if (line != NULL)
		{
			game->map.map_size[i] = (char *)malloc((ft_strlen(line) + 1)
					* sizeof(char));
			ft_strcpy(game->map.map_size[i], line);
			free(line);
			i++;
			y++;
		}
	}
	game->map.map_size[i] = NULL;
}

static void	init_map_set_dimensions(t_game *game)
{
	game->map.map_width = ft_strlen(game->map.map_size[0]) - 1;
	game->map.map_height = map_height(game);
}

static void	init_map_allocate_memory(t_game *game)
{
	size_t	y;

	y = 0;
	if (!game->map.fd)
		error(ERROR_INIT_MAP);
	game->map.map_size = (char **)malloc(MAP_HEIGHT * sizeof(char *));
	if (!game->map.map_size)
		error(ERROR_INIT_MAP);
	allocate_memory(game, y);
	game->map.y = y;
}

void	init_map(t_game *game)
{
	init_map_allocate_memory(game);
	init_map_set_dimensions(game);
}

// DISPLAY MAP WITH SPRITES
void	display_assets(t_game *game)
{
	int	image_x;
	int	image_y;
	int	x;
	int	y;

	y = 0;
	put_image(game, "./assets/bg2.xpm", 0, 1);
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			image_x = x * IMAGE_WIDTH;
			image_y = y * IMAGE_HEIGHT;
			if (game->map.map_size[y][x] == '1')
				put_image(game, "./assets/wall.xpm", image_x, image_y);
			else if (game->map.map_size[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				put_image(game, "./assets/ped.xpm", image_x, image_y);
			}
			else if (game->map.map_size[y][x] == 'E')
				put_image(game, "./assets/house.xpm", image_x, image_y);
			x++;
		}
		y++;
	}
}
