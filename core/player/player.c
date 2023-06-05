/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:40:48 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/05 05:05:13 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	update(t_game *game, int x, int _y)
{
	char *relative_path; 
	
	relative_path = "./assets/bg2.xpm";
	put_image(game, relative_path, game->player.x, game->player.y);
	put_image(game, relative_path, x, _y);
}

void right(t_game *game)
{
    int i;
    int j;
    char *relative_path;

    relative_path = "./assets/ped_right.xpm";
    i = game->player.y;
    j = game->player.x + 1;
	printf("\n%d\n", check_wall(game));
    if (check_wall(game) == 1)
    {
        // Le mouvement est autorisé, effectuez les mises à jour nécessaires
        game->player.mouv++;
        game->player.x = j;
        update(game, j, i);
        put_image(game, relative_path, j, i);
    }
    else
    {
        printf("Mouvement interdit vers la droite.\n");
    }
}

void left(t_game *game)
{
    int i;
    int j;
    char *relative_path;

    relative_path = "./assets/ped_left.xpm";
    i = game->player.y;
    j = game->player.x - 1;
    if (check_wall(game) == 1)
    {
        // Le mouvement est autorisé, effectuez les mises à jour nécessaires
        game->player.mouv++;
        game->player.x = j;
        update(game, j, i);
        put_image(game, relative_path, j, i);
    }
    else
    {
        printf("Mouvement interdit vers la gauche.\n");
    }
}

void up(t_game *game)
{
    int i;
    int j;
    char *relative_path;

    relative_path = "./assets/ped.xpm";
    i = game->player.y - 1;
    j = game->player.x;
    if (check_wall(game) == 1)
    {
        // Le mouvement est autorisé, effectuez les mises à jour nécessaires
        game->player.mouv++;
        game->player.y = i;
        update(game, j, i);
        put_image(game, relative_path, j, i);
    }
    else
    {
        printf("Mouvement interdit vers le haut.\n");
    }
}

void down(t_game *game)
{
    int i;
    int j;
    char *relative_path;

    relative_path = "./assets/ped_down.xpm";
    i = game->player.y + 1;
    j = game->player.x;
    if (check_wall(game) == 1)
    {
        // Le mouvement est autorisé, effectuez les mises à jour nécessaires
        game->player.mouv++;
        game->player.y = i;
        update(game, j, i);
        put_image(game, relative_path, j, i);
    }
    else
    {
        printf("Mouvement interdit vers le bas.\n");
    }
}

