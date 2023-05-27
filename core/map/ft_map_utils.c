/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 01:56:08 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/13 20:56:53 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

// Récupérer le nombre de lignes dans le fichier .ber
int	ft_linelen(char *path)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_printf(ERROR_LINELEN);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			i++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (i);
}

// Récupérer les colonnes dans le fichier .ber
void	ft_columnlen(int row, int column, int i, t_game *game)
{
	char *line;

	line = get_next_line(game->map.fd);
	while (line != NULL)
	{
		game->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!game->map.map[row])
			return (ft_free(game->map.map));
		while (line[i] != NULL)
		{
			column++;
			i++;
			game->map.map[row][column] = line[i];
		}
		row++;
		game->map.map[row][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(game->map.fd);
	}
	game->map.map[row] = NULL;
}
