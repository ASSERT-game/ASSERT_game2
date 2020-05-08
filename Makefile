# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: home <home@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/06 17:51:42 by home              #+#    #+#              #
#    Updated: 2020/05/07 20:25:08 by home             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_g2
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/ -I ~/.brew/include
SDL_LIB = -L ~/.brew/lib -l SDL2

SRCS_DIR = srcs/
BINARY_DIR = bin/

DEBUG_NAMES = \
	test \

SRCS_NAMES = \
	main \

FILE_NAMES = \
	$(SRCS_NAMES) \
	$(addprefix debug/, $(DEBUG_NAMES))

OBJ_NAMES = \
	$(addsuffix .o, $(SRCS_NAMES)) \
	$(addsuffix .o, $(DEBUG_NAMES)) \

SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR), $(FILE_NAMES)))
OBJS = $(addprefix $(BINARY_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(BINARY_DIR) $(OBJS)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(SDL_LIB)

$(BINARY_DIR)%.o: %.c
	mkdir -p $(BINARY_DIR)$(dir $<)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

$(BINARY_DIR):
	mkdir $(BINARY_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

save: fclean
	git add .
	git commit -m "$(MSG)"
	git push

re: fclean all

run: re
	clear
	@echo "\033[1m\033[32m$(NAME)\033[0m"
	@./$(NAME)
