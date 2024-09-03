# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msisto <msisto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 10:55:41 by msisto            #+#    #+#              #
#    Updated: 2024/04/29 14:38:39 by msisto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FLAGS = -Wall -Wextra -Werror

MINILIBX_PATH = ./mlx

MINILIBX = $(MINILIBX_PATH)/libmlx.a

CC = gcc

SRC = main.c get_next_line.c get_next_line_utils.c ft_caramba.c ft_caramba1.c \
		ft_caramba2.c ft_printf.c ft_outputs.c ft_calloc.c ft_map_generation.c \
		ft_movement.c ft_movement1.c ft_movement2.c ft_movement3.c ft_mapgen2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MINILIBX)
	gcc $(OBJ) $(CFLAGS) $(MINILIBX) mlx/libmlx.a -L./mlx -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(MINILIBX):
	make -C $(MINILIBX_PATH)
