NAME			= so_long
GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m
LIBFT			= ./libft/libft.a
MLX				= ./minilibx-linux/libmlx.a
MLX_FLAGS		= -L./minilibx-linux -lmlx -lXext -lX11 -lm
CC				= cc
FLAGS			= -Wall -Werror -Wextra
VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
				--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes --suppressions=mlx.supp
REMOVE			= rm -f
SRCS_DIR		= ./sources/
SRCS			= $(addprefix $(SRCS_DIR),	\
				main.c						\
				check_map_1.c				\
				exit_and_errors.c			\
				init_game.c					\
				init_map.c					\
				render.c					\
				load_images.c)

all:			${NAME}

${NAME}:		${SRCS}
				${CC} ${FLAGS} -I./minilibx-linux ${SRCS} ${LIBFT} -o ${NAME} ${MLX_FLAGS}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

clean:
				@echo "Nothing to clean (no object files)"
				@echo

fclean:			
				${REMOVE} ${NAME}
				@echo "${NAME}: ${RED}${NAME} was deleted${RESET}"
				@echo

re:				fclean all

run:			${NAME}
				${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

.PHONY:			all clean fclean re run
