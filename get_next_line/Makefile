# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 18:23:42 by cchaudeu          #+#    #+#              #
#    Updated: 2025/08/19 00:19:31 by cchaudeu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
AR = ar rcs
all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
