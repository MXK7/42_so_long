/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:02:56 by mpoussie          #+#    #+#             */
/*   Updated: 2023/05/31 07:11:36 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAP_WIDTH 10
# define MAP_HEIGHT 10
# include "include/libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h> // TODO DELETE

# define true 1
# define false 0
# define bool int

# define SIZE 48
# define MAP_HEIGHT 10

# define ERROR_LINELEN "An error occurred while reading the file [@FT_LINELEN:23]"
# define ERROR_INIT_MAP "An error has occurred while executing the map. [@INIT_MAP]"
# define ERROR_CHECK_WALL "An error has occurred while executing the map. [@CHECK_WALL]"
# define ERROR_MAIN "Too many or too few arguments, we were initialized. [@MAIN]"
# define ERROR_IMAGE_LOAD "Image failed to load. [@PUT_IMAGE]"

# define UNDEFINED_GAME "The game cannot be launched. [@DISPLAY_ASSETS]"
# define UNDEFINED_IMAGE "Image not defined or not found. [@PUT_IMAGE]"

typedef struct s_player
{
	int			*x;
	int			*y;

}				t_player;

typedef struct s_map
{
	int			fd;

	int			map_width;
	int			map_height;

	int			x;
	int			y;

	char		*path;
	char		**map_size;

	void		*mlx;
	void		*mlx_window;
	void		*xpm;
}				t_map;

typedef struct s_game
{
	t_player	player;
	t_map		map;
}				t_game;

// ############# UTILS ############# //
void			error(char *str);
void			*put_image(t_game *game, char *relative_path, int x, int y);
int				ft_map_height(t_game *game);
void			map_destroy(t_game *game);
int				destroy_window(t_game *game);

// ############# MAP ############# //
void			init_map(t_game *game);
int				check_shape(t_game *game);
int				check_wall(t_game *game);
void			display_assets(t_game *game);

#endif
