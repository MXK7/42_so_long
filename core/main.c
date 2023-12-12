/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:52:22 by mpoussie          #+#    #+#             */
/*   Updated: 2023/12/08 21:52:14 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_key(int key_code, t_game *game)
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

void	init_var(t_game *game)
{
	game->map.fd = 0;
	game->map.weaponItems = 0;
	game->player.mouv = 0;
	game->init = 1;
	game->map.info.weaponItems = 0;
	game->map.info.empty = 0;
	game->map.info.house = 0;
	game->map.info.ped = 0;
	game->map.info.wall = 0;
	game->map.info.weapon = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error(ERROR_MAIN);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		error(UNDEFINED_FILE);
	init_var(&game);
	game.map.fd = open(argv[1], O_RDONLY);
	init_map(&game);
	game.map.mlx = mlx_init();
	game.map.mlx_window = mlx_new_window(game.map.mlx, game.map.map_width
			* IMAGE_WIDTH, game.map.map_height * IMAGE_HEIGHT,
			"Little Theft Auto (by MXK7)");
	init_assets(&game);
	display_assets(&game);
	check_map(&game);
	mlx_hook(game.map.mlx_window, 17, 1L << 2, destroy_window, &game);
	mlx_hook(game.map.mlx_window, 2, 1, check_key, &game);
	mlx_loop(game.map.mlx);
}
