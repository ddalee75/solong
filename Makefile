# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chilee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 17:45:01 by chilee            #+#    #+#              #
#    Updated: 2022/01/24 16:35:02 by chilee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

SRCS = $(addprefix sources/srcs/, \
	so_long.c \
	moves.c \
	matrix_creation.c \
	map_checkers.c \
	hooks.c \
	cleaner.c \
	game_init.c \
	game_load.c \
	message_ascii.c \
	)

OBJS_SRCS = $(SRCS:.c=.o)

LIB = ./librairies/libft/libft.a ./librairies/minilibx/libmlx.a -lXext -lX11 -lm

all: $(NAME)

MLX = ./librairies/minilibx/libmlx.a

$(MLX):
	@echo "$(shell tput setaf 2) Building Minilibx$(shell tput sgr0)"
	@make -sC librairies/minilibx > /dev/null 2> /dev/null
	@echo "$(shell tput setaf 2) Building LIBFT $(shell tput sgr0)"

%.o:%.c
	 $(CC) $(FLAG) -c $< -o $@

$(NAME):$(OBJS_SRCS) $(MLX)
	@$(MAKE) -C ./librairies/libft/
	@$(CC) $(FLAGS) -L./librairies/libft/ -lft -o $(NAME) $(OBJS_SRCS) $(LIB)
	@echo "$(shell tput setaf 2)SUCCESS \"so_long\" created $(shell tput sgr0)"

clean:
	@rm -rf $(OBJS_SRCS)
	@make clean -sC librairies/libft > /dev/null
	@make clean -sC librairies/minilibx > /dev/null
	@echo "$(shell tput setaf 2) All files.o cleaned$(shell tput sgr0)"

fclean: clean
	@echo "$(shell tput setaf 2) Projet cleaned$(shell tput sgr0)"
	@rm -rf $(NAME)
	
re:fclean all
