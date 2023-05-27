/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 04:31:45 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/21 03:21:15 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_init_map(t_game *game)
{
	game->map.x = 0;
	game->map.y = 0;
	game->map.line_len = 0;
	game->map.fd = NULL;
	game->map.path = NULL;
}

void	ft_map_display(char *path, t_game *game)
{
	int row;
	int i;
	size_t column;

	i = 0;
	row = 0;
	column = 0;
	game->map.path = path;
	game->map.line_len = ft_linelen(game->map.path);
	game->map.map = ft_calloc(game->map.line_len + 1, sizeof(char *));
	if (!game->map.map)
		return (NULL);
	game->map.fd = open(path, O_RDONLY);
	if (game->map.fd < 0)
		ft_printf(ERROR_MAPDISPLAY);
	else
	{
		ft_display_assets(&game);
		ft_columnlen(row, column, i, game);
		close(game->map.fd);
	}
}

int	ft_display_assets(t_game *game)
{
	game->map.mlx_wall_path = "./assets/init/wall.xpm";
	game->map.mlx_bg_path = "./assets/init/black.xpm";
	game->map.mlx_ply_path = "./assets/ply/ghost_right1.xpm";
	game->map.mlx_portal_path = "./assets/init/portal.xpm";

	game->map.mlx = mlx_init();
	game->map.mlx_win = mlx_new_window(game->map.mlx, 800, 600, "PAF (PAC-MAN) by Mehdi");

	game->map.x = 0;
	while (game->map.x < MAP_WIDTH)
	{
		game->map.x++;
		game->map.y = 0;
		while (game->map.y < MAP_HEIGHT)
		{
			game->map.y++;
			if (game->map.map[game->map.x][game->map.y] == '1')
			{
				game->map.mlx_wall = mlx_xpm_file_to_image(game->map.mlx, game->map.mlx_wall_path, &game->map.x, &game->map.y);
					// WALL
			}
			else if (game->map.map[game->map.x][game->map.y] == '0')
			{
				game->map.mlx_bg = mlx_xpm_file_to_image(game->map.mlx, game->map.mlx_bg_path, &game->map.x, &game->map.y);
					// BACKGROUND
			}
			else if (game->map.map[game->map.map.x][game->map.y] == 'P')
			{
				game->map.mlx_ply = mlx_xpm_file_to_image(game->map.mlx, game->map.mlx_ply_path, &game->map.x, &game->map.y);
					// PLAYER
			}
			else if (game->map.map[game->map.x][game->map.y] == 'E')
			{
				game->map.mlx_portal = mlx_xpm_file_to_image(game->map.mlx, game->map.mlx_portal_path, &game->map.x, &game->map.y);
					// PORTAL
			}
		}
	}
	mlx_loop(game->map.mlx);
	return (0);
}

int main(void)
{
	t_game	game;

	ft_init_map(&game);
	ft_map_display("map.ber", &game);	
	if (game.map.map)
		ft_free(game.map.map);
}
