/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:02:56 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/05 04:00:36 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAP_WIDTH 10
# define MAP_HEIGHT 10

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define IMAGE_WIDTH 32
# define IMAGE_HEIGHT 32

# include "include/libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h> 
# include <stdio.h> // TODO DELETE
# include <stdlib.h> // TODO DELETE
# include <string.h> // TODO DELETE

# define true 1
# define false 0
# define bool int

# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53
# define SIZE   48

# define ERROR_LINELEN "An error occurred while reading the file [@FT_LINELEN:23]"
# define ERROR_INIT_MAP "An error has occurred while executing the map. [@INIT_MAP]"
# define ERROR_CHECK_WALL "An error has occurred while executing the map. [@CHECK_WALL]"
# define ERROR_MAIN "Too many or too few arguments, we were initialized. [@MAIN]"
# define ERROR_IMAGE_LOAD "Image failed to load. [@PUT_IMAGE]"

# define UNDEFINED_GAME "The game cannot be launched. [@DISPLAY_ASSETS]"
# define UNDEFINED_IMAGE "Image not defined or not found. [@PUT_IMAGE]"
# define UNDEFINED_WINDOW "File not opened. [@SIZE_WINDOWS]"
# define UNDEFINED_FILE "This file is not a .ber. [@SIZE_WINDOWS]"

typedef struct s_player
{
	int			x;
	int			y;

	int 		player_check;
	int 		exit_check;
	int			corner_check;

	int 		corner;
	int 		mouv;

}				t_player;

typedef struct s_map
{
	int			fd;

	int			map_width;
	int			map_height;
	int 		image_width;
	int 		image_height;
	int 		x_offset;
	int 		y_offset;

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
void			map_destroy(t_game *game);
int				map_height(t_game *game);
int				destroy_window(t_game *game);

// ############# MAP ############# //
void			init_map(t_game *game);
void			display_assets(t_game *game);
int				check_shape(t_game *game);
int				check_wall(t_game *game);

// ############# PLAYER ############# //
int				key_check(int key_code, t_game *game);
int				move_check(t_game *game, int i, int j);
void			update(t_game *game, int x, int _y);
void			right(t_game *game);
void			left(t_game *game);
void			down(t_game *game);
void			up(t_game *game);

#endif