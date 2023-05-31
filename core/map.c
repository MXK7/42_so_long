/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:52:20 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/31 07:35:40 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// OPEN FOLDER MAP
void	init_map(t_game *game)
{
	int		i;
	bool	x;
	size_t	map_height;
	char	*line;

	i = 0;
	x = true;
	map_height = 0;
	if (!game->map.fd)
		error(ERROR_INIT_MAP);
	game->map.map_size = (char **)malloc(MAP_HEIGHT * sizeof(char *));
		// Allouer la mémoire pour game->map.map_size
	if (!game->map.map_size)
		error(ERROR_INIT_MAP);
	while (x != false)
	{
		line = get_next_line(game->map.fd);
		if (line == NULL)
		{
			x = false;
		}
		else
		{
			game->map.map_size[i] = (char *)malloc((ft_strlen(line) + 1)
					* sizeof(char));
			ft_strcpy(game->map.map_size[i], line);
			// printf("INIT_MAP:\n%s", game->map.map_size[i]);
			free(line);
			i++;
			map_height++;
		}
	}
	game->map.y = map_height; // Assigner la hauteur de la carte
}

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

int	check_wall(t_game *game)
{
	int	top;
	int	bottom;
	int	right;
	int	left;

	top = 0;
	bottom = 0;
	right = 0;
	left = 0;
	if (!game->map.map_size)
		error(ERROR_CHECK_WALL);
	while (game->map.map_size[top] != NULL)
	{
		if (game->map.map_size[right][ft_strlen(game->map.map_size[right])
			- 1] != '1')
			return (0);
		top++;
	}
	while (game->map.map_size[bottom] != NULL)
	{
		if (game->map.map_size[bottom][ft_strlen(game->map.map_size[bottom])
			- 1] != '1')
			return (0);
		bottom++;
	}
	while (left < bottom)
	{
		if (game->map.map_size[left][0] != '1')
			return (0);
		left++;
	}
	while (right < bottom)
	{
		if (game->map.map_size[right][ft_strlen(game->map.map_size[right])
			- 1] != '1')
			return (0);
		right++;
	}
	return (1);
}

// DISPLAY MAP WITH SPRITES
void	display_assets(t_game *game)
{
	int		image_width;
	int		image_height;
	int		x_offset;
	int		y_offset;
	int		image_x;
	int		image_y;
	int		x;
	int		y;

	game->map.map_width = ft_strlen(game->map.map_size[0]);
	game->map.map_height = ft_map_height(game);
	printf("\nMap height: %d\nMap width: %d\n", game->map.map_height, game->map.map_width);
	image_width = 64;
	image_height = 64;
	x_offset = (800 - (image_width * game->map.map_width)) / 2;
	y_offset = (600 - (image_height * game->map.map_height)) / 2;
	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			image_x = x_offset + x * image_width;
			image_y = y_offset + y * image_height;
			if (game->map.map_size[y][x] == '1')
				put_image(game, "./assets/wall.xpm", image_x, image_y);
			else if (game->map.map_size[y][x] == '0')
				put_image(game, "./assets/bg.xpm", image_x, image_y);
			else if (game->map.map_size[y][x] == 'P')
				put_image(game, "./assets/ped.xpm", image_x, image_y);
			else if (game->map.map_size[y][x] == 'E')
				put_image(game, "./assets/house.xpm", image_x, image_y);
			x++;
		}
		y++;
	}
}
