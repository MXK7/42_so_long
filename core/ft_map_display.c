/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 04:31:45 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/10 19:01:13 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_map_display(char map[MAP_WIDTH][MAP_HEIGHT])
{
	void *mlx;
	void *mlx_win;
	int x, y;

	void *mlx_wall;
	char *mlx_wall_path;
    void *mlx_bg;
    char *mlx_bg_path;
	void *mlx_ply;
	char *mlx_ply_path;

	mlx_wall_path = "./assets/init/wall.xpm";
    mlx_bg_path = "./assets/init/black.xpm";
    mlx_ply_path = "./assets/ply/";

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "PAF");

	x = 0;
	y = 0;

	while (x < MAP_WIDTH)
	{
		x++;
		while (y < MAP_HEIGHT)
		{
			y++;
			if (map[x][y] == '1')
			{
				mlx_wall = mlx_xpm_file_to_image(mlx, mlx_wall_path, x * 32, y * 32);
			}
			else if (map[x][y] == '0')
			{
				mlx_bg = mlx_xpm_file_to_image(mlx, mlx_bg_path, x * 32, y * 32);
			}
			else if (map[x][y] == 'P')
			{
				mlx_ply = mlx_xpm_file_to_image(mlx, mlx_ply_path, x * 32, y * 32); // joueur vert
			}
			else if (map[x][y] == 'E')
			{
				mlx_pixel_put(mlx, mlx_win, x, y, 0xFF0000); // sortie rouge
			}
		}
	}

	mlx_loop(mlx);
	return (0);
}