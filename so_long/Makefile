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

LIBFT			= ./libft/libft.a

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

all:			${LIBFT} ${NAME}

${NAME}:		
				${CC} ${SRCS} ${LIBFT} ${FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

clean:
				make clean -C libraries/Libft
				@echo

fclean:
				${REMOVE} ${NAME} ${NAME_BONUS}
				@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
				@echo

re:				fclean all

run:			${NAME}
				${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

.PHONY:			all clean fclean re valgrind run
