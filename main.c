/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:59:03 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/09 16:56:54 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	int fd;
	char *line[MAP_WIDTH + 1];
	char map[MAP_WIDTH][MAP_HEIGHT];
	int i, j;

	fd = open("map.txt", O_RDONLY);
	if (fd < 0)
		exit(0);
	i = 0;
	while (get_next_line(fd, line) > 0)
	{
		j = 0;
		while (j < MAP_WIDTH && line[j])
		{
			map[i][j] = line[j];
			j++;
		}
		map[i][j];
		i++;
	}
	close(fd);
	ft_map_display(map);
	return(0);
}
