# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: home <home@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/06 17:51:42 by home              #+#    #+#              #
#    Updated: 2020/05/07 03:15:16 by home             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_g2
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/

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

P_OBJS = $(SRCS:.c=.o)

OBJS = $(addprefix $(BINARY_DIR), $(OBJ_NAMES))

all:
	make $(NAME)

$(NAME): $(P_OBJS)
	make install
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

install: $(BINARY_DIR)
	mv $(OBJ_NAMES) $(BINARY_DIR)

%.o: %.c
	gcc $(FLAGS) $(INCLUDES) -c $<

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
