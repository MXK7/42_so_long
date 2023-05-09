/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:02:56 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/09 05:41:33 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAP_WIDTH 10
# define MAP_HEIGHT 10

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int ft_map_display(char map[MAP_WIDTH][MAP_HEIGHT]);

#endif