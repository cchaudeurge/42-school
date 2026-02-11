# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 15:22:40 by cchaudeu          #+#    #+#              #
#    Updated: 2025/12/10 17:26:03 by cchaudeu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIBFT_DIR		= ./libft
LIBFT			= $(LIBFT_DIR)/libft.a
MLX_DIR			= ./minilibx-linux
MLX				= $(MLX_DIR)/libmlx.a
MLX_FLAGS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
CC				= cc

FLAGS			= -Wall -Werror -Wextra

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
				--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE			= rm -f

SRCS_DIR		= ./sources/

SRCS			= $(addprefix $(SRCS_DIR),	\
				main.c						\
				check_map_1.c				\
				exit_and_errors.c			\
				init_game.c					\
				init_map.c					\
				init_render_and_player.c	\
				load_images.c)

OBJS			= $(SRCS:.c=.o)

all:			${LIBFT} ${NAME}

${NAME}:		${OBJS}
				${CC} ${FLAGS} ${SRCS} ${LIBFT} -o ${NAME} ${MLX_FLAGS}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

clean:
				${REMOVE} ${OBJS}
				make clean -C ./libft
				@echo

fclean:
				clean
				${REMOVE} ${NAME}
				make fclean -C ./libft
				@echo "${NAME}: ${RED}${NAME} was deleted${RESET}"
				@echo

re:				fclean all

run:			${NAME}
				${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

.PHONY:			all clean fclean re valgrind run
