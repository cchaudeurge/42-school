NAME			= push_swap
#BONUS_NAME		= push_swap_bonus
GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m
LIBFT			= ./libft/libft.a
CC				= cc
FLAGS			= -Wall -Werror -Wextra
VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
				--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes --suppressions=mlx.supp
REMOVE			= rm -f

SRCS_DIR		= ./sources/
#BONUS_DIR		= ./sources_bonus/
SRCS			= $(addprefix $(SRCS_DIR),	\
				main.c						\
				parse.c						\
				stacks_init.c				\
				lis.c						\
				cleanup.c)
#BONUS_SRCS		= $(addprefix $(BONUS_DIR),		\
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
				${CC} ${FLAGS} ${SRCS} ${LIBFT} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

#bonus:			${BONUS_NAME}

#${BONUS_NAME}:	${BONUS_SRCS}
				#${CC} ${FLAGS} -I./minilibx-linux ${BONUS_SRCS} ${LIBFT} -o ${BONUS_NAME} ${MLX_FLAGS}
#				@echo "$(BONUS_NAME): $(GREEN)$(BONUS_NAME) was compiled with bonus.$(RESET)"
#				@echo

clean:
				@echo "Nothing to clean (no object files)"
				@echo

fclean:			
				${REMOVE} ${NAME} #${BONUS_NAME}
				#@echo "${NAME}: ${RED}${NAME} and ${BONUS_NAME} were deleted${RESET}"
				#@echo

re:				fclean all

#run:			${NAME}
#				${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

#run_bonus:		${BONUS_NAME}
#				${VALGRIND} ./${BONUS_NAME} assets/maps/valid/bonus/map5.ber

PHONY:			all clean fclean re
