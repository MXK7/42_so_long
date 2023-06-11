/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:40:48 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/11 22:56:00 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	right(t_game *game)
{
	int		i;
	int		j;
	char	*relative_path;

	relative_path = "./assets/ped_right.xpm";
	i = game->player.y;
	j = game->player.x + 32;
	printf("\ncheck_move:%d\nY:%d\nX:%d", check_move(game, j, i), i, j);
	if (check_move(game, j, i) == 1)
	{
		game->player.x = j;
		game->player.mouv++;
		display_assets(game);
		put_image(game, relative_path, j, i);
	}
	else
	{
		printf("Mouvement interdit vers la droite.\n");
	}
}

void	left(t_game *game)
{
	int		i;
	int		j;
	char	*relative_path;

	relative_path = "./assets/ped_left.xpm";
	i = game->player.y;
	j = game->player.x - 32;
	printf("\ncheck_move:%d\nY:%d\nX:%d", check_move(game, j, i), i, j);
	if (check_move(game, j, i) == 1)
	{
		game->player.x = j;
		game->player.mouv++;
		display_assets(game);
		put_image(game, relative_path, j, i);
	}
	else
	{
		printf("Mouvement interdit vers la gauche.\n");
	}
}

void	up(t_game *game)
{
	int		i;
	int		j;
	char	*relative_path;

	relative_path = "./assets/ped.xpm";
	i = game->player.y - 32;
	j = game->player.x;
	printf("\ncheck_move:%d\nY:%d\nX:%d", check_move(game, j, i), i, j);
	if (check_move(game, j, i) == 1)
	{
		game->player.y = i;
		game->player.mouv++;
		display_assets(game);
		put_image(game, relative_path, j, i);
	}
	else
	{
		printf("Mouvement interdit vers le haut.\n");
	}
}

void	down(t_game *game)
{
	int		i;
	int		j;
	char	*relative_path;

	relative_path = "./assets/ped_back.xpm";
	i = game->player.y + 32;
	j = game->player.x;
	printf("\ncheck_move:%d\nY:%d\nX:%d", check_move(game, j, i), i, j);
	if (check_move(game, j, i) == 1)
	{
		game->player.y = i;
		game->player.mouv++;
		display_assets(game);
		put_image(game, relative_path, j, i);
	}
	else
	{
		printf("Mouvement interdit vers le bas.\n");
	}
}
