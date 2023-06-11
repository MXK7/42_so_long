/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:52:22 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/11 22:37:23 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_check(int key_code, t_game *game)
{
	if (key_code == 65307)
		destroy_window(game);
	if (key_code == 65362)
		up(game);
	if (key_code == 65363)
		right(game);
	if (key_code == 65361)
		left(game);
	if (key_code == 65364)
		down(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.init = 1;
	if (argc != 2)
		error(ERROR_MAIN);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		error(UNDEFINED_FILE);
	game.map.fd = open(argv[1], O_RDONLY);
	init_map(&game);
	game.map.mlx = mlx_init();
	game.map.mlx_window = mlx_new_window(game.map.mlx, game.map.map_width
			* IMAGE_WIDTH, game.map.map_height * IMAGE_HEIGHT,
			"Little Theft Auto (by MXK7)");
	display_assets(&game);
	put_image(&game, "./assets/ped.xpm", game.player.x, game.player.y);
	mlx_hook(game.map.mlx_window, 17, 1L << 2, destroy_window, &game);
	mlx_key_hook(game.map.mlx_window, key_check, &game);
	mlx_loop(game.map.mlx);
}
