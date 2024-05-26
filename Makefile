# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 00:32:01 by baptiste          #+#    #+#              #
#    Updated: 2024/05/27 00:51:32 by baptiste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror -g

NAME := todo-app

SRC := main.c \
		src/parse/parse.c \
		src/init/init.c \
		src/utils/ft_itoa.c \
		src/utils/ft_strlen.c \
		src/execution/exec.c \
		src/utils/print_banner.c \
		src/utils/get_nb_lines.c \
		src/utils/get_next_line.c \
		src/utils/ft_putnbr_fd.c \
		src/utils/ft_printf_fd.c \
		src/utils/ft_putstr_fd.c \

OBJS_DIR := obj
OBJS    := $(addprefix $(OBJS_DIR)/,$(SRC:.c=.o))

all: $(NAME)


$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lreadline

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re