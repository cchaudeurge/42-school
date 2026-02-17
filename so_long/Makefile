NAME			= so_long
BONUS_NAME		= so_long_bonus
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
BONUS_DIR		= ./sources_bonus/
SRCS			= $(addprefix $(SRCS_DIR),	\
				main.c						\
				game_init_and_controls.c	\
				game_loop.c					\
				game_render.c				\
				map_parse.c					\
				map_validate_1.c			\
				map_validate_2.c			\
				errors_and_exit.c			\
				images_load.c)
BONUS_SRCS		= $(addprefix $(BONUS_DIR),		\
				main_bonus.c					\
				game_init_and_controls_bonus.c	\
				game_loop_bonus.c				\
				game_render_bonus.c				\
				map_parse_bonus.c				\
				map_validate_1_bonus.c			\
				map_validate_2_bonus.c			\
				errors_and_exit_bonus.c			\
				images_load_bonus.c)

all:			${NAME}

${NAME}:		${SRCS}
				${CC} ${FLAGS} -I./minilibx-linux ${SRCS} ${LIBFT} -o ${NAME} ${MLX_FLAGS}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

bonus:			${BONUS_NAME}

${BONUS_NAME}:	${BONUS_SRCS}
				${CC} ${FLAGS} -I./minilibx-linux ${BONUS_SRCS} ${LIBFT} -o ${BONUS_NAME} ${MLX_FLAGS}
				@echo "$(BONUS_NAME): $(GREEN)$(BONUS_NAME) was compiled with bonus.$(RESET)"
				@echo

clean:
				@echo "Nothing to clean (no object files)"
				@echo

fclean:			
				${REMOVE} ${NAME} ${BONUS_NAME}
				@echo "${NAME}: ${RED}${NAME} and ${BONUS_NAME} were deleted${RESET}"
				@echo

re:				fclean all

run:			${NAME}
				${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

run_bonus:		${BONUS_NAME}
				${VALGRIND} ./${BONUS_NAME} assets/maps/valid/bonus/map5.ber

PHONY:			all bonus clean fclean re run run_bonus
