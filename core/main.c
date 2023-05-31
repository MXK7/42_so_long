/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:52:22 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/31 07:21:14 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        error(ERROR_MAIN);
    game.map.fd = open(argv[1], O_RDONLY);
    init_map(&game);
    check_shape(&game);
    check_wall(&game);
    game.map.mlx = mlx_init();
    game.map.mlx_window = mlx_new_window(game.map.mlx, 800, 600, "Little Theft Auto (by MXK7)");
    display_assets(&game);
    mlx_loop(game.map.mlx);
}
