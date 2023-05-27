/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:02:56 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/27 19:26:09 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAP_WIDTH 10
# define MAP_HEIGHT 10
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define ERROR_LINELEN "An error occurred while reading the file [@FT_LINELEN:23]"
# define ERROR_MAPDISPLAY ""

typedef struct s_player
{
	int			*x;
	int			*y;

}				t_player;

typedef struct s_map
{
	int			**map;
	int			*x;
	int			*y;
	int			line_len;
	int			fd;
	char		*path;

	void *mlx;
	void *mlx_win;
	void *mlx_wall;
	char *mlx_wall_path;
	void *mlx_bg;
	char *mlx_bg_path;
	void *mlx_ply;
	char *mlx_ply_path;
	void *mlx_portal;
	char *mlx_portal_path;
}				t_map;

typedef struct s_game
{
	t_player	player;
	t_map		map;
}				t_game;

// ############# MAP ############# //
int				ft_linelen(char *path);
void			ft_free(char **tab);
void			ft_init_map(t_game *game);
int				ft_display_assets(t_game *game);
void			ft_columnlen(int row, int column, int i, t_game *game);

#endif
