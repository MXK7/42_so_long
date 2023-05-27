# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 17:19:09 by mpoussie          #+#    #+#              #
#    Updated: 2023/05/13 18:47:20 by mpoussie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror

SRCS    		=	main.c \
					core/map/ft_map_display.c \
					core/map/ft_map_utils.c \

all: ${NAME}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(SRCS)
	$(CC) $(SRCS) ./libft/libft.a ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME)

clean:
				$(RM) $(NAME)
fclean:			clean
				$(RM) $(NAME)	
re: fclean ${NAME}

.PHONY: all, clean, fclean, re