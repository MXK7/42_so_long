/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 04:31:45 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/09 05:41:30 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_map_display(char map[MAP_WIDTH][MAP_HEIGHT])
{
	void	*mlx;
	void	*mlx_win;
    int x, y;

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
                mlx_pixel_put(mlx, mlx_win, x, y, 0xFFFFFF); // mur blanc
            }
            else if (map[x][y] == '0')
            {
                mlx_pixel_put(mlx, mlx_win, x, y, 0x000000); // sol noir
            }
            else if (map[x][y] == 'P')
            {
                mlx_pixel_put(mlx, mlx_win, x, y, 0x00FF00); // joueur vert
            }
            else if (map[x][y] == 'E')
            {
                mlx_pixel_put(mlx, mlx_win, x, y, 0xFF0000); // sortie rouge
            }
        }
    }

	mlx_loop(mlx);
    return 0;
}