# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 20:02:54 by mrehberg          #+#    #+#              #
#    Updated: 2022/11/05 11:43:40 by mrehberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

SRC_DIR := src/
MAP := maps/simple_map.ber
LIBFT := libft/libft.a
MLX_DIR := minilibx_opengl_20191021
MLX_DIR_LIX := minilibx-linux
MLX := $(MLX_DIR)/libmlx.a
MLX_LIX := $(MLX_DIR_LIX)/libmlx.a

SRC := $(SRC_DIR)so_long.c \
 $(SRC_DIR)checks.c \
 $(SRC_DIR)checks_2.c \
 $(SRC_DIR)checks_path.c \
 $(SRC_DIR)draw_window.c \
 $(SRC_DIR)move_player.c \


OBJS := $(SRC:.c=.o)

CC := gcc

CFLAGS := -Wall -Werror -Wextra

C_TEST_FLAGS := -Wall -Wextra -g

all: $(NAME)

$(NAME): Makefile $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

make_test: Makefile $(SRC)
	make -C $(MLX_DIR)
	make -C libft
	$(CC) $(C_TEST_FLAGS) $(SRC) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit -lz -o $(NAME)

make_linux: Makefile $(SRC)
	make -C $(MLX_DIR_LIX)
	make -C libft
	$(CC) $(C_TEST_FLAGS) $(SRC) $(LIBFT) $(MLX_LIX) -lmlx -lXext -lX11 -o $(NAME)

t: make_test
	./$(NAME) $(MAP)

tl: make_linux
	./$(NAME) $(MAP)

l: make_test
	export MallocStackLogging=0
	leaks -atExit --list -- ./$(NAME) $(MAP)

ll: make_test
	export MallocStackLogging=1
	leaks -atExit --list -- ./$(NAME) $(MAP)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *.out
	make fclean -C libft

re: fclean t

.PHONY: all clean fclean re make_printf_libft make_test sep str err leaks