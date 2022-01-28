# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chilee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 17:45:01 by chilee            #+#    #+#              #
#    Updated: 2022/01/26 16:17:38 by chilee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS = so_long_bonus

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

SRCS_BONUS = $(addprefix sources/srcs_bonus/, \
	so_long_bonus.c \
	moves_bonus.c \
	frames_bonus.c \
	matrix_creation_bonus.c \
	map_checkers_bonus.c \
	hooks_bonus.c \
	game_load_bonus.c \
	game_init_bonus.c \
	cleaner_bonus.c \
	message_ascii_bonus.c \
	)

OBJS_SRCS_BONUS = $(SRCS_BONUS:.c=.o)

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

bonus: $(BONUS)

$(BONUS):$(OBJS_SRCS_BONUS) $(MLX)
	$(MAKE) -C ./librairies/libft/
	$(CC) $(FLAGS) -L./librairies/libft/ -lft -o $(BONUS) $(OBJS_SRCS_BONUS) $(LIB)
	@echo "$(shell tput setaf 2)SUCESS \"so_long_bonus\" created$(shell tput sgr0)"

clean:
	@rm -rf $(OBJS_SRCS) $(OBJS_SRCS_BONUS)
	@make clean -sC librairies/libft > /dev/null
	@make clean -sC librairies/minilibx > /dev/null
	@echo "$(shell tput setaf 2) All files.o cleaned$(shell tput sgr0)"

fclean: clean
	@echo "$(shell tput setaf 2) Projet cleaned$(shell tput sgr0)"
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	
re:fclean all
