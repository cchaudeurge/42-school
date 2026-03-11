NAME			= push_swap

BONUS_NAME		= checker

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

CC				= cc
FLAGS			= -Wall -Werror -Wextra
VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
				--track-origins=yes --quiet --tool=memcheck	--keep-debuginfo=yes
REMOVE			= rm -f
SRCS_DIR		= ./sources/
BONUS_DIR		= ./sources_bonus/
SRCS			= $(addprefix $(SRCS_DIR),	\
				main.c						\
				parse.c						\
				stacks_init.c				\
				lis.c						\
				operations.c				\
				optimizations.c				\
				target.c					\
				cost.c						\
				empty_b.c					\
				move_list.c					\
				cleanup.c)
BONUS_SRCS		= $(addprefix $(BONUS_DIR),		\
				main_bonus.c					\
				parse_bonus.c					\
				operations_bonus.c				\
				cleanup_bonus.c)
OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)
INCL			= -I./libft
LIBFT_DIR		= ./libft
LIBFT			= $(LIBFT_DIR)/libft.a

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT)
				$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

bonus:			$(BONUS_NAME)

$(BONUS_NAME):	$(BONUS_OBJS) | $(LIBFT)
				$(CC) $(FLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
				@echo "$(BONUS_NAME): $(GREEN)$(BONUS_NAME) was compiled with bonus.$(RESET)"
				@echo

$(LIBFT):
				@$(MAKE) -C $(LIBFT_DIR)

%.o:			%.c
				$(CC) $(FLAGS) $(INCL) -c $< -o $@

clean:			
				$(REMOVE) $(OBJS) $(BONUS_OBJS)
				$(MAKE) clean -C $(LIBFT_DIR)

fclean:			clean
				$(REMOVE) $(NAME) $(BONUS_NAME)
				$(MAKE) fclean -C $(LIBFT_DIR)
				@echo "$(NAME): $(RED)$(NAME) and $(BONUS_NAME) were deleted$(RESET)"
				@echo

re:				fclean all

.PHONY:			all bonus clean fclean re
