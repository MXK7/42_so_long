/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:46:35 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/31 07:19:41 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], i);
		i++;
	}
	return ;
}

int	ft_map_height(t_game *game)
{
	int	map_height;

	map_height = 0;
	while (ft_strchr(game->map.map_size[map_height], '\n') != NULL)
	{
		map_height++;
	}
	return (map_height);
}

void	map_destroy(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map_size[y] != NULL)
	{
		free(game->map.map_size[y]);
		y++;
	}
}

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->map.mlx, game->map.mlx_window);
	map_destroy(game);
	exit(0);
}

void	*put_image(t_game *game, char *relative_path, int x, int y)
{
	int window_width = 800;  // Remplacez par la largeur réelle de votre fenêtre
	int window_height = 600; // Remplacez par la hauteur réelle de votre fenêtre
	if (x >= 0 && x < window_width && y >= 0 && y < window_height)
	{
		mlx_put_image_to_window(game->map.mlx, game->map.mlx_window,
				game->map.xpm, x, y);
	}
	if (access(relative_path, F_OK) != -1)
	{
		game->map.xpm = mlx_xpm_file_to_image(game->map.mlx, relative_path, &game->map.x, &game->map.y);
		if (game->map.xpm != NULL)
		{
			mlx_put_image_to_window(game->map.mlx, game->map.mlx_window,
					game->map.xpm, x, y);
		}
		else
		{
			error(ERROR_IMAGE_LOAD);
			destroy_window(game);
			return (0);
		}
	}
	else
	{
		error(UNDEFINED_IMAGE);
		destroy_window(game);
		return (0);
	}
	return (game->map.xpm);
}
