/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:02:56 by mpoussie          #+#    #+#             */
/*   Updated: 2023/06/16 05:33:52 by mpoussie         ###   ########.fr       */
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
# include "include/minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>  // TODO DELETE
# include <stdlib.h> // TODO DELETE
# include <string.h> // TODO DELETE

# define true 1
# define false 0
# define bool int

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define SIZE 48

# define ERROR_LINELEN "An error occurred while reading the file [@FT_LINELEN:23]"
# define ERROR_INIT_MAP "An error has occurred while executing the map. [@INIT_MAP]"
# define ERROR_CHECK_WALL "An error has occurred while executing the map. [@CHECK_WALL]"
# define ERROR_MAIN "Too many or too few arguments, we were initialized. [@MAIN]"
# define ERROR_IMAGE_LOAD "Image failed to load. [@PUT_IMAGE]"
# define ERROR_MAP "Map not functional. [@MAIN]"

# define UNDEFINED_GAME "The game cannot be launched. [@DISPLAY_ASSETS]"
# define UNDEFINED_WINDOW "File not opened. [@SIZE_WINDOWS]"
# define UNDEFINED_FILE "This file is not a .ber. [@SIZE_WINDOWS]"
# define UNDEFINED_MALLOC "Malloc is not defined. [@MAP_INIT]"

typedef struct s_info
{
	int			weaponItems;

	int			weapon;
	int			ped;
	int			house;
	int			wall;
	int			empty;
}				t_info;

typedef struct s_player
{
	int			x;
	int			y;
	int			mouv;
}				t_player;

typedef struct s_map
{
	t_info		info;

	int			fd;

	int			map_width;
	int			map_height;

	int			house_x;
	int			house_y;

	int			x;
	int			y;

	char		**map_size;

	void		*mlx;
	void		*mlx_window;

	void		*bg;
	void		*ped;
	void		*ped_right;
	void		*ped_left;
	void		*ped_back;
	void		*wall;
	void		*weapon;
	void		*empty;
	void		*house;

	int			weaponItems;

}				t_map;

typedef struct s_game
{
	t_player	player;
	t_map		map;
	int			init;
}				t_game;

// ############# UTILS ############# //
void			error(char *str);
void			destroy_map(t_game *game);
int				destroy_window(t_game *game);
int				check_key(int key_code, t_game *game);

// ############# MAP ############# //
int				height_map(t_game *game);
int				len_map(char *str);
int				check_shape(t_game *game);

void			init_map(t_game *game);
void			init_assets(t_game *game);
void			check_map(t_game *game);
void			display_assets(t_game *game);
void			display_empty(t_game *game, int x, int y);
void			display_wall(t_game *game, int x, int y);
void			display_house(t_game *game, int x, int y);
void			display_player(t_game *game, int x, int y);
void			display_weapon(t_game *game, int x, int y);

// ############# PLAYER ############# //
int				check_move(t_game *game, int new_x, int new_y);

void			update_move(t_game *game);
void			right(t_game *game);
void			left(t_game *game);
void			down(t_game *game);
void			up(t_game *game);

#endif